# AirWatcher

## Auteurs
Ce projet a été réalisé par les binômes suivants :
- **B3231** : Louis Labory et Daniel Massila
- **BYYYY** : Aaron Berton et William Michaux

## Description
AirWatcher est une application de surveillance de la qualité de l'air. Elle permet de collecter, analyser et afficher des données sur la pollution atmosphérique afin d'aider les utilisateurs à mieux comprendre et gérer leur environnement.

## Installation
1. Clonez le dépôt :
    ```bash
    git clone https://github.com/WiredMind2/AirWatcher.git
    ```
2. Accédez au répertoire :
    ```bash
    cd AirWatcher
    ```
3. Suivez les instructions spécifiques au projet pour configurer l'environnement.

## Compilation
1. Assurez-vous d'avoir un compilateur C++ installé (par exemple, `g++`).
2. Compilez le projet en exécutant la commande suivante dans le répertoire racine :
    ```bash
    g++ -o AirWatcher src/*.cpp
    ```

## Utilisation
1. Lancez l'application :
    ```bash
    ./AirWatcher
    ```
2. Utilisez la commande suivante pour lancer l'application en mode test :  
    ```bash
    ./AirWatcher test
    ```

## Fonctionnement du Menu Principal

Lorsque vous lancez l'application, un menu s'affiche pour sélectionner le type d'utilisateur. Voici les options disponibles :

1. **Agence gouvernementale** : Sélectionnez cette option si vous représentez une agence gouvernementale.
2. **Individu** : Sélectionnez cette option si vous êtes un utilisateur individuel.
3. **Fournisseur** : Sélectionnez cette option si vous êtes un fournisseur de services ou de données.

Pour faire un choix, entrez le numéro correspondant à votre rôle (1, 2 ou 3) lorsque l'application vous le demande.

Le menu principal se lance ensuite automatiquement après la sélection du type d'utilisateur. Voici les sous-menus disponibles dans le menu principal :

- **1** : Analyse de données
- **2** : Statistiques
- **3** : Points utilisateurs
- **4** : Administration (uniquement pour les agences gouvernementales)
- **0** : Quitter l'application
