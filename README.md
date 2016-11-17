# Travail pratique 2

## Description

Description du projet en quelques phrases.
Mentionner le contexte (cours, sigle, université, etc.).

## Auteurs

- Jean-Lou Hallée (HALJ05129309)
- Olivier Levasseur (LEVO19109301)

## Plateformes supportées

Indiquez ici la liste des plateformes sur lesquelles le projet a été testé
(MacOS, Ubuntu, Mint, Serveur Matl etc.). N'oubliez pas de préciser la version
de la plateforme (MacOS 10.10.5 Yosemite, Ubuntu 14.04 LTS, etc.).

## Dépendances

Donnez la liste des bibliothèques et des logiciels qui doivent être installées
pour que le projet soit fonctionnel. Donnez le lien vers ceux-ci pour que
l'utilisateur puisse être redirigé vers les sites officiels des
logiciels/bibliothèques pour effectuer l'installation le cas échéant. N'oubliez
pas d'indiquer

## Installation

Expliquez comment rendre le projet fonctionnel (commandes make et make data ?)
et comment lancer la suite de tests automatiques (make test ?), comment
nettoyer le dossier (make clean ?).

## Fonctionnement
Exemple 1:
Entrée:
~~~~
    bin/tp2 --country ury
~~~~

Affiche:
~~~~
    Name : Oriental Republic of Uruguay
    Code : URY
~~~~

Exemple 2:
Entrée:
~~~~
    bin/tp2 --country afg --show-capital --show-languages --show-borders
~~~~

Affiche:
~~~~   
    Name : Islamic Republic of Afghanistan
    Code : AFG
    Capital : Kabul
    Langues: Dari, Pashto, Turkmen
    Borders : IRN, PAK, TKM, UZB, TJK, CHN
~~~~

Exemple 3:
Entrée:
~~~~
     bin/tp2 --country arm --show-languages --show-capital --show-borders --show-flag --output-format dot
~~~~

Affiche:
~~~~
 graph {
    ARM [
        shape = none
        label = <<table border="0" cellspacing="0">
            <tr><td align="center" border="1" fixedsize="true" width="200" height="100"><img src="data/countries/data/arm.png" scale="true"/></td></tr>
            <tr><td align="left" border="1"><b>Name</b>: Republic of Armenia</td></tr>
            <tr><td align="left" border="1"><b>Code</b>: ARM</td></tr>
            <tr><td align="left" border="1"><b>Capital</b>: Yerevan</td></tr>
            <tr><td align="left" border="1"><b>Language</b>: Armenian, Russian</td></tr>
            <tr><td align="left" border="1"><b>Borders</b>: AZE, GEO, IRN, TUR</td></tr>
        </table>>
    ];
}
~~~~

## Contenu du projet

Décrivez brièvement chacun des fichiers contenus dans le projet. Utilisez
une liste à puce et décrivez-les de façon significative (une phrase par
fichier)

## Références

Citez vos sources ici, s'il y a lieu.

## Statut

Indiquez le statut actuel du projet et les bogues connus s'il y a lieu. Aussi,
utilisez cette section pour indiquer la liste des tâches à effectuer pour
compléter le projet en utilisant le [format spécial
Markdown](https://docs.gitlab.com/ce/user/markdown.html#task-lists) :

- [x] Module graphviz

  - [x] Transformation en format graphviz (responsable: Olivier)

- [x] Module countries

  - [x] Lecture du format jansson (responsable: Olivier)

- [x] Module input

  - [x] Lecture et vérification des entrées (responsable : Jean-Lou) 

- [x] Module output

  - [ ] Intégration des modules input, countries et graphviz 
        afin d'afficher correctement(responsable: Jean-Lou)

- [x] Module exécutable

  - [x] Intégration de tous les modules afin de créer 
        un exécutable fonctionnel (responsable: Jean-Lou)

- [x] Module util

  - [x] Fonctions utiles n'appartenant pas à un module en particulier
        (responsable: Olivier)

- [ ] Tests (responsable: Jean-Lou et Olivier)


- [ ] Autres

  - [ ] Makefile (responsable: Jean-Lou)

  - [ ] Respect de la structure des répertoires (responsable: Jean-Lou)
