# AirWatcher

## Auteurs
Ce projet a été réalisé par les binômes suivants :
- **B3231** : Louis Labory et Daniel Massila
- **B3226** : Aaron Berton et William Michaud

## Description
AirWatcher est une application de surveillance de la qualité de l'air. Elle permet de collecter, analyser et afficher des données sur la pollution atmosphérique afin d'aider les utilisateurs à mieux comprendre et gérer leur environnement.

## Installation et lancement
1. Clonez le dépôt :
    ```bash
    git clone https://github.com/WiredMind2/AirWatcher.git
    ```
2. Accédez au répertoire :
    ```bash
    cd AirWatcher
    ```
3. Compilez le projet (nécessite un compilateur C++ et `make`) :
    ```bash
    make
    ```
4. Lancez l'application :
    ```bash
    ./AirWatcher
    ```
   ou, pour le mode test :
    ```bash
    ./AirWatcher test
    ```

## Manuel Utilisateur

### Lancement et navigation

1. **Sélection du type d'utilisateur** :
   - 1 : Agence gouvernementale
   - 2 : Individu
   - 3 : Fournisseur

2. **Menu principal** :
   - 1 : Analyse de données
   - 2 : Statistiques
   - 3 : Points utilisateurs
   - 4 : Administration (réservé à l'agence gouvernementale)
   - 0 : Quitter

---

### Détail des fonctionnalités

#### Analyse de données
- **1. Analyse des données des capteurs** :
  - Estime la qualité de l'air à une position donnée (latitude, longitude, période, k voisins).
- **2. Identifier capteurs non fiables** :
  - Affiche les capteurs considérés comme non fiables selon des critères automatiques.
- **3. Analyser impact des purificateurs** :
  - Compare la qualité de l'air autour d'un purificateur avant/après une période donnée.
- **0. Retour au menu principal**

#### Statistiques
- **1. Qualité moyenne de l'air par zone** :
  - Estime la qualité de l'air sur une zone circulaire (centre, rayon, k voisins).
- **2. Qualité moyenne de l'air par point** :
  - Estime la qualité de l'air à un point précis (latitude, longitude, k voisins).
- **3. Classer capteurs similaires** :
  - Recherche et affiche les capteurs similaires à un capteur de référence.
- **0. Retour au menu principal**

#### Points utilisateurs
- **1. Consulter les points d'un utilisateur** :
  - Affiche le nombre de points d'un utilisateur à partir de son identifiant.
- **0. Retour au menu principal**

#### Administration (agence gouvernementale uniquement)
- **1. Consulter capteurs défaillants** :
  - Recherche et affiche les capteurs considérés comme défaillants sur une période et une zone données.
- **2. Marquer un capteur comme non fiable** :
  - Permet de marquer un capteur comme non fiable (après sélection dans la liste des capteurs défaillants).
- **3. Marquer un utilisateur comme malicieux** :
  - Permet de signaler un utilisateur comme malicieux (il ne pourra plus accumuler de points).
- **0. Retour au menu principal**

---

### Conseils d'utilisation
- Saisissez toujours des valeurs valides (nombres, dates au format AAAA-MM-JJ, etc.).
- Les menus guident l'utilisateur pas à pas et affichent des messages d'erreur en cas de saisie incorrecte.
- L'option Administration n'est accessible qu'aux agences gouvernementales.

Pour toute question, consultez le code source ou contactez les auteurs du projet.
