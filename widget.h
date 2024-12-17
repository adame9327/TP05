#ifndef WIDGET_H
#define WIDGET_H

// Inclut les bibliothèques nécessaires
#include <QWidget>  // Pour la classe de base QWidget
#include <QLabel>   // Pour utiliser des étiquettes (labels) dans l'interface utilisateur

// Déclaration de la classe Widget qui hérite de QWidget
class Widget : public QWidget
{
    Q_OBJECT  // Macro nécessaire pour activer les fonctionnalités des signaux et des slots dans Qt

public:
    // Constructeur explicite avec un paramètre parent optionnel
    explicit Widget(QWidget *parent = nullptr);
    
    // Destructeur de la classe Widget
    ~Widget();

private:
    // Déclaration d'un pointeur vers QLabel pour afficher un texte ou des informations
    QLabel *starsLabel;
};

#endif // WIDGET_H

