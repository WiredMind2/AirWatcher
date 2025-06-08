/*************************************************************************
analyse.h  -  Déclaration des fonctions d'analyse des données de qualité de l'air (statistiques, anomalies, etc.).
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface des fonctions d'analyse (fichier analyse.h) -----------

//------------------------------------------------------------------------
// Rôle des fonctions d'analyse
// Permet d'analyser les données de qualité de l'air pour extraire des informations utiles.
//------------------------------------------------------------------------

#pragma once

void analyse_donnees_capteurs();
void identifier_capteurs_non_fiables();
void analyser_impact_purificateurs();
time_t demander_date(const string &desc);
double demander_coord(const string &desc);
