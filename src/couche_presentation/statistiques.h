/*************************************************************************
 statistiques.h  -  Déclare les fonctions de calcul et d'affichage des statistiques sur la qualité de l'air et l'utilisation de l'application.
 -------------------
 début                : Avril 2025
 auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
 e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

#pragma once

//---------- Interface des fonctions statistiques (fichier statistiques.h) -----------

//--------------------------------------------------- Interfaces utilisées
// (Aucune interface additionnelle requise pour ce fichier)

//------------------------------------------------------------------------
// Rôle des fonctions statistiques
// Permet de calculer et d'afficher des statistiques sur la qualité de l'air et l'utilisation.
//------------------------------------------------------------------------

void calculQualiteAirPos();
void calculQualiteAirZone();
void classerCapteursSimilaires();
void trouverCapteursDetournes();
void listerCapteursSimilaires();