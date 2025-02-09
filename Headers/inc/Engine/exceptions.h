#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

// Classe d'exception personnalisée
class Exception : public std::exception {
public:
    // Constructeur qui prend un message d'erreur
    explicit Exception(const std::string& message) : msg(message) {}

    // Surcharge de la méthode `what()` pour retourner le message d'erreur
    const char* what() const noexcept override {
        return msg.c_str();  // Retourne le message d'erreur
    }

private:
    std::string msg;  // Message d'erreur
};

#endif
