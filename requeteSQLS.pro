# Inclure les modules nécessaires de Qt
QT += core gui sql                      # Ajoute les modules Core, GUI, et SQL
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  # Si Qt version > 4, inclure le module Widgets

# Configurer la version C++ à utiliser
CONFIG += c++17                         # Utiliser le standard C++17

# Définir le type de projet
TEMPLATE = app                          # Type de projet : application

# Nom de l'exécutable cible
TARGET = requeteSQL                     # Nom du fichier généré après compilation

# Spécifier les fichiers sources
SOURCES += \
    main.cpp \                          # Fichier principal avec la fonction main()
    widget.cpp                          # Fichier source pour la classe Widget

# Spécifier les fichiers d'en-tête
HEADERS += \
    widget.h                            # Fichier d'en-tête pour la classe Widget

# Spécifier les fichiers d'interface utilisateur
FORMS += \
    widget.ui                           # Fichier UI pour la classe Widget (créé avec Qt Designer)

# Définir les chemins pour le déploiement (section facultative)
unix:!android: target.path = /opt/$${TARGET}/bin  # Chemin cible pour l'installation sous Unix (hors Android)
!isEmpty(target.path): INSTALLS += target        # Si le chemin cible est défini, ajouter aux cibles d'installation

