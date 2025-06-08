/*************************************************************************
Administration.h  -  Déclaration des fonctions d'administration pour la gestion des utilisateurs, capteurs, et droits d'accès dans AirWatcher.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

//---------- Interface des fonctions d'administration (fichier Administration.h) -----------

//------------------------------------------------------------------------
// Rôle des fonctions d'administration
// Permet de gérer les capteurs défaillants, marquer les capteurs non fiables et signaler les utilisateurs malicieux.
//------------------------------------------------------------------------

#pragma once

void consulter_capteurs_defaillants();
void marquer_capteur_non_fiable();
void marquer_user_malicieux();

