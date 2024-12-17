#include <QApplication>
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLabel>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Création de la fenêtre principale
    QMainWindow w;
    w.resize(500, 200);

    // Création du QTableWidget pour afficher les données
    QTableWidget *tableWidget = new QTableWidget(&w);
    tableWidget->setGeometry(10, 10, 500, 300); // Position et taille
    tableWidget->setColumnCount(3); // Trois colonnes
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Nom" << "Club" << "Note");

    // Connexion à la base de données MySQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");           // Nom de la base de données
    db.setHostName("127.0.0.1");          // Hôte local
    db.setPort(3306);                     // Port par défaut MySQL
    db.setUserName("adame");              // Nom d'utilisateur
    db.setPassword("Passciel2");          // Mot de passe

    // Vérification de la connexion
    if (db.open()) {
        qDebug() << "Connexion réussie à " << db.hostName();

        // Création et exécution de la requête SQL pour récupérer les données
        QSqlQuery query;
        query.exec("SELECT * FROM jeu");

        int row = 0; // Index de ligne dans le QTableWidget

        // Parcours des résultats de la requête
        while (query.next()) {
            QString Nom = query.value(1).toString();  // Récupération du nom
            QString club = query.value(2).toString(); // Récupération du club
            int note = query.value(3).toInt();        // Récupération de la note

            // Insérer une nouvelle ligne dans le tableau
            tableWidget->insertRow(row);

            // Ajouter les valeurs récupérées dans les cellules correspondantes
            tableWidget->setItem(row, 0, new QTableWidgetItem(Nom));
            tableWidget->setItem(row, 1, new QTableWidgetItem(club));

            // Afficher les étoiles pour la note dans un QLabel
            QLabel *starsLabel = new QLabel();
            QString stars = QString("★").repeated(note); // Convertir la note en étoiles
            starsLabel->setText(stars);
            starsLabel->setAlignment(Qt::AlignCenter);
            tableWidget->setCellWidget(row, 2, starsLabel);

            row++; // Passer à la ligne suivante
            qDebug() << Nom << club << note; // Affichage dans la console pour le débogage
        }
    } else {
        // En cas d'échec de connexion
        qDebug() << "Échec de la connexion :" << db.lastError().text();
    }

    // Connecter le signal itemChanged pour permettre les mises à jour
    QObject::connect(tableWidget, &QTableWidget::itemChanged, [&](QTableWidgetItem *item) {
        int row = item->row();    // Récupération de la ligne modifiée
        int col = item->column(); // Récupération de la colonne modifiée
        QString newValue = item->text(); // Nouvelle valeur saisie par l'utilisateur

        // Mise à jour dans la base de données selon la colonne modifiée
        if (col == 0) { // Colonne "Nom"
            QString updateQueryStr = QString("UPDATE jeu SET nom = '%1' WHERE id = %2")
                                     .arg(newValue)
                                     .arg(row + 1);
            QSqlQuery updateQuery;
            if (!updateQuery.exec(updateQueryStr))
                qDebug() << "Erreur mise à jour Nom :" << updateQuery.lastError().text();
        } else if (col == 1) { // Colonne "Club"
            QString updateQueryStr = QString("UPDATE jeu SET club = '%1' WHERE id = %2")
                                     .arg(newValue)
                                     .arg(row + 1);
            QSqlQuery updateQuery;
            if (!updateQuery.exec(updateQueryStr))
                qDebug() << "Erreur mise à jour Club :" << updateQuery.lastError().text();
        } else if (col == 2) { // Colonne "Note"
            bool ok;
            int newNote = newValue.toInt(&ok); // Conversion de la valeur en entier
            if (ok) {
                QString updateQueryStr = QString("UPDATE jeu SET note = %1 WHERE id = %2")
                                         .arg(newNote)
                                         .arg(row + 1);
                QSqlQuery updateQuery;
                if (!updateQuery.exec(updateQueryStr))
                    qDebug() << "Erreur mise à jour Note :" << updateQuery.lastError().text();
            } else {
                qDebug() << "Valeur Note invalide!"; // Message d'erreur si la note est invalide
            }
        }
    });

    // Afficher la fenêtre principale
    w.show();
    return a.exec();
}

