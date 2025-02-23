#pragma once
#include <unordered_map>
#include <string>
#include "score_data.hpp"
#include "scene_tag.hpp"

class ScoreManager {
public:
    // Création de l'instance du singleton
    static ScoreManager* CreateInstance();
    
    // Accès à l'instance du singleton
    static ScoreManager* GetInstance();

    // Accesseurs
    int getCurrentScore(SceneTag mode) const;
    int getBestScore(SceneTag mode) const;
    void setCurrentScore(SceneTag mode, int score);
    void setBestScore(SceneTag mode, int score);

    // Sauvegarde et chargement
    bool saveScores(const std::string& filename);
    bool loadScores(const std::string& filename);

private:
    // Constructeur privé
    ScoreManager();
    
    // Suppression de la copie et de l'affectation
    ScoreManager(const ScoreManager&) = delete;
    ScoreManager& operator=(const ScoreManager&) = delete;

    // Instance unique du singleton
    static ScoreManager* instance;

    // Données de score par mode de jeu
    std::unordered_map<SceneTag, ScoreData> scores;
};
