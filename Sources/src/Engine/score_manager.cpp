#include "score_manager.hpp"
#include <fstream>
#include <iostream>
#include "assert.h"

// Initialisation de l'instance du singleton
ScoreManager* ScoreManager::instance = nullptr;

// Création de l'instance du singleton
ScoreManager* ScoreManager::CreateInstance() {
    assert(!instance);
    instance = new ScoreManager();
    return instance;
}

// Récupération de l'instance du singleton
ScoreManager* ScoreManager::GetInstance() {
    assert(instance);
    return instance;
}

// Constructeur privé
ScoreManager::ScoreManager() {
    // Initialisation des scores pour chaque mode de jeu
    scores[SceneTag::Game] = {0, 0};
}

// Obtenir le score actuel
int ScoreManager::getCurrentScore(SceneTag mode) const {
    return scores.at(mode).currentScore;
}

// Obtenir le meilleur score
int ScoreManager::getBestScore(SceneTag mode) const {
    return scores.at(mode).bestScore;
}

// Modifier le score actuel
void ScoreManager::setCurrentScore(SceneTag mode, int score) {
    scores[mode].currentScore = score;
    // Mettre à jour le meilleur score si nécessaire
    if (score > scores[mode].bestScore)
        scores[mode].bestScore = score;
}

// Modifier le meilleur score
void ScoreManager::setBestScore(SceneTag mode, int score) {
    scores[mode].bestScore = score;
}

// Sauvegarde des scores en binaire
bool ScoreManager::saveScores(const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour écriture : " << filename << std::endl;
        return false;
    }
    // Écrire chaque mode de jeu et ses scores
    for (const auto& [mode, score] : scores) {
        ofs.write(reinterpret_cast<const char*>(&mode), sizeof(SceneTag));
        ofs.write(reinterpret_cast<const char*>(&score), sizeof(ScoreData));
    }
    return true;
}

// Chargement des scores depuis un fichier binaire
bool ScoreManager::loadScores(const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);

    // Si le fichier n'existe pas, on initialise les scores à zéro
    if (!ifs) {
        std::cerr << "Fichier non trouvé : " << filename << ". Initialisation des scores à zéro." << std::endl;
        scores[SceneTag::Game] = {0, 0};
        scores[SceneTag::GameHard] = {0, 0};
        scores[SceneTag::MainMenu] = {0, 0};
        return false;
    }

    while (ifs.good()) {
        SceneTag mode;
        ScoreData score;

        // Tente de lire le mode
        if (!ifs.read(reinterpret_cast<char*>(&mode), sizeof(SceneTag)))
            break;  // Sort de la boucle si la lecture échoue

        // Tente de lire le score
        if (!ifs.read(reinterpret_cast<char*>(&score), sizeof(ScoreData)))
            break;  // Sort si impossible de lire le score

        this->scores[mode] = score;
    }

    return true;
}
