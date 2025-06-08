/*************************************************************************
Administration.h  -  Déclaration des fonctions d'administration métier pour la gestion des utilisateurs, capteurs, et droits d'accès.
-------------------
début                : Avril 2025
auteurs              : Aaron Berton, William Michaud (B3226) - Louis Labory, Daniel Massila (B3231)
e-mails              : aaron.berton@insa-lyon.fr, william.michaud@insa-lyon.fr, louis.labory@insa-lyon.fr, daniel.massila@insa-lyon.fr
*************************************************************************/

#pragma once

// Permet de consulter les capteurs détectés comme défaillants ou malicieux,
//  de marquer un capteur comme non fiable, de marquer un utilisateur comme malicieux.

void consulter_capteurs_defaillants();
void marquer_capteur_non_fiable();
void marquer_user_malicieux();