# Application Qt pour la Gestion et l'Affichage des Données d'une Base MySQL

Cette application est un programme informatique qui permet de gérer et d'afficher des informations sur des joueurs de football à partir d'une base de données. Imaginez une grande feuille de calcul où vous pouvez voir, ajouter et modifier des informations.

## Objectif du Projet

L'objectif de ce projet est de créer une application qui peut :
1. Se connecter à une base de données où sont stockées des informations sur les joueurs.
2. Afficher ces informations dans un tableau.
3. Permettre de modifier ces informations et de voir les changements en temps réel.

## Fonctionnalités

- **Connexion à une base de données MySQL** : 
  - L'application se connecte à une base de données sécurisée en utilisant des identifiants (comme un nom d'utilisateur et un mot de passe).
- **Affichage des données** :
  - Les informations sur les joueurs (leur nom, club et note) sont affichées dans un tableau interactif.
  - Par exemple, chaque ligne du tableau contient :
    - Le nom du joueur
    - Le club du joueur
    - Une note, représentée par des étoiles.
- **Mise à jour dynamique** :
  - Si vous modifiez une information dans le tableau, elle est automatiquement mise à jour dans la base de données.
  - Les erreurs sont gérées et affichées dans la console (la partie où les messages du programme s'affichent).
- **Personnalisation de l'affichage** :
  - Les notes des joueurs sont affichées sous forme d'étoiles pour une meilleure lisibilité.

## Prérequis

### Système requis

Pour faire fonctionner ce projet, vous aurez besoin de :
- **Qt Framework (version 5 ou supérieure)** : Un ensemble d'outils pour créer des interfaces graphiques en C++.
- **MySQL Server (version 8.0 ou supérieure)** : Un logiciel qui gère la base de données.
- **C++17 (ou version plus récente)** : Une version du langage de programmation C++.
- **Qt Creator IDE (facultatif)** : Un environnement de développement intégré pour écrire et gérer le code plus facilement.

### Base de données

Vous aurez besoin d'une base de données MySQL avec une table appelée `jeu` pour stocker les informations des joueurs. Voici un script SQL pour créer cette table et y insérer des données initiales :

```sql
CREATE TABLE `jeu` (
  `id` int NOT NULL AUTO_INCREMENT,
  `prenom` varchar(255) DEFAULT NULL,
  `club` varchar(255) DEFAULT NULL,
  `note` int DEFAULT NULL,
  PRIMARY KEY (`id`)
);

INSERT INTO `jeu` VALUES 
  (1, 'Ronaldo', 'madride', 3),
  (2, 'Grizou', 'juventus', 5);
```

STRUCTURE DU PROJET 

Projet/
├── fichier_tp05.sql         # Script SQL pour créer la table et insérer des données
├── main.cpp                 # Point d'entrée principal du programme
├── widget.cpp               # Implémentation de la classe Widget
├── widget.h                 # Déclaration de la classe Widget
├── requeteSQL.pro           # Fichier de configuration Qt
└── README.md                # Documentation (ce fichier)

Instructions d’installation et d’exécution
Étape 1 : Configuration de la base de données

    Installez et démarrez MySQL.
    Exécutez le script SQL fichier_tp05.sql pour créer la table et insérer des données.

Étape 2 : Configuration du projet Qt

    Clonez ou téléchargez le projet dans un répertoire local.
    Ouvrez le fichier requeteSQL.pro dans Qt Creator.
    Configurez un kit de développement avec un compilateur compatible (C++17).

Étape 3 : Compilation et exécution

    Compilez le projet dans Qt Creator ou via les commandes suivantes :

qmake && make

Lancez l’exécutable généré :

    ./requeteSQL

Utilisation

    Connexion à la base de données :
    Assurez-vous que MySQL est actif et que les paramètres (nom de la base, utilisateur, mot de passe) dans main.cpp sont corrects.

    Affichage des données :
    Les données de la table jeu sont chargées automatiquement dans le tableau lors du démarrage.

    Modification des données :
        Double-cliquez sur une cellule pour modifier son contenu.
        Les changements sont automatiquement sauvegardés dans la base de données.

Exemple de fonctionnement
Exemple de table dans MySQL
Nom	Club	Note
Ronaldo	madride	★★★
Grizou	juventus	★★★★★
Sortie console

Connexion réussie à 127.0.0.1
Chargement des données...
Ronaldo madride 3
Grizou juventus 5

Interface utilisateur

Un tableau affichant les données avec les colonnes Nom, Club, et Note (étoiles).
Points d'amélioration possibles

    Gestion avancée des erreurs : Ajouter des messages d'erreur plus descriptifs pour les échecs de connexion ou de mise à jour.
    Ajout de fonctionnalités :
        Ajout d'une colonne pour les statistiques ou d'autres informations sur les joueurs.
        Possibilité de supprimer ou d'ajouter des lignes via l'interface.
    Sécurité :
        Chiffrer les identifiants de connexion à la base.
        Utiliser des requêtes préparées pour éviter les injections SQL.
    Tests : Ajouter des tests unitaires pour valider les fonctionnalités principales.
