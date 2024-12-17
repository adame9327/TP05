#include "widget.h"
#include <QString>

// Constructeur de la classe Widget
Widget::Widget(QWidget *parent) : QWidget(parent) // Appel du constructeur parent QWidget avec un paramètre parent
{
    // Création d'un QLabel qui sera utilisé pour afficher du texte ou des informations
    starsLabel = new QLabel(this); // starsLabel est un enfant de Widget
    // Définition de la géométrie (position et taille) du QLabel dans la fenêtre
    starsLabel->setGeometry(200, 150, 100, 30); // Position x=200, y=150, largeur=100, hauteur=30
}

// Destructeur de la classe Widget
Widget::~Widget()
{
    // Suppression de l'objet QLabel pour libérer la mémoire allouée dynamiquement
    delete starsLabel;
}

