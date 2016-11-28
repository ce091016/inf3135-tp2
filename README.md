# Travail pratique 2

## Description
- Ce projet permet d'aller chercher dans informations concernant des pays dans une base de donnée de format 'Json'. En effet, le sous-module 'countries' permet d'aller retrouver les informations que l'utilisateur souhaite avoir. (Nom pays, code pays, frontières, langues et drapeau.) 
- L'utilisateur peut choisir de voir un seul, pays, une région entière ou tous les pays de la base de données.
Veuillez entrer la commande 'bin/tp2 --help' pour plus d'informations
- Ce projet a été réalisé dans le cadre du cours Construction et maintenance de logiciels (INF3135) à l'Université du Québec à Montréal.

## Auteurs

- Jean-Lou Hallée (HALJ05129309)
- Olivier Levasseur (LEVO19109301)

## Plateformes supportées

Ce projet a été testé sur une seule plateforme : Ubuntu 16.04 LTS.
Cependant, il devrait être fonctionnel sur les autres versions de linux et sur MacOs.

## Dépendances

Ce projet utilise les outils 'Graphviz', 'CUnit', 'Bats' et 'Jansson'. Il utilise également le projet 'countries' en tant que sous-module.

* Graphviz: http://www.graphviz.org/Download.php
* CUnit: https://sourceforge.net/projects/cunit/
* Bats: https://github.com/sstephenson/bats
* Jansson: https://github.com/akheron/jansson
* countries: https://github.com/ablondin/countries

## Installation

- Afin de rendre le projet fonctionnel, il suffit de se rendre à la racine du projet et d'entrer la commande 'make data'. Ceci permettera au projet d'ajouter ou de mettre à jour le sous-module countries.
- Pour compiler le projet, demeurer dans le répertoire racine du projet et entrer la commande 'make'.
- Afin de nettoyer les dossiers des fichiers objets, fichiers 'dot, fichiers 'text' et fichiers 'png', il suffit d'entrer la commande à la racine du projet 'make clean'.

## Fonctionnement
**Entrée:**
~~~~
    bin/tp2 --country ury
~~~~

**Sortie:**
~~~~
    Name : Oriental Republic of Uruguay
    Code : URY
~~~~

**Entrée:**
~~~~
    bin/tp2 --country afg --show-capital --show-languages --show-borders
~~~~

**Sortie:**
~~~~   
    Name : Islamic Republic of Afghanistan
    Code : AFG
    Capital : Kabul
    Langues: Dari, Pashto, Turkmen
    Borders : IRN, PAK, TKM, UZB, TJK, CHN
~~~~

**Entrée:**
~~~~
     bin/tp2 --country arm --show-languages --show-capital --show-borders --show-flag --output-format dot
~~~~

**Sortie:**
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

**Racine du projet**
* .gitignore: contient une liste de fichiers que Git peut ignorer lors d'un commit
* .gitlab-ci.yml: fichier permettant l'intégration continue des tests
* .gitmodules: 
* Makefile: fichier permettant une compilation rapide et un nettoyage de repertoires rapide
* README.md: fichier contenant les informations importantes sur le projet
* testsBats.bats: la serie de tests que le projet doit verifier

**Répertoire src**
* tp2.c: code source du fichier exécutable
* countries.c: code source permettant de manipuler la base de données countries.json
* countries.h: en-tête du fichier countries.c
* graphviz.c: code source permettant de générer des fichiers au format .dot pour représenter 
              graphiquement les pays de la base de données countries.json
* graphviz.h: en-tête du fichier graphviz.c
* input.c: code source permettant de gérer les entrées de l'utilisateur
* input.h: en-tête du fichier input.c
* output.c: code source permettant de gérer tous les cas de sorties (différents formats)
* output.h: en-tête du fichier output.c
* util.c: contient des fonctions utiles qui peuvent n'appartiennent pas à un module en particulier
* util.h: en-tête du fichier util.c


## Références

Citez vos sources ici, s'il y a lieu.

## Statut

- Aucun bogue reconnu pour l'instant.

- Cependant, une optimisation de la création du fichier '.png' devrait être accomplie; il serait préférable d'éviter la création du fichier temporaire.

- [x] Module graphviz

  - [x] Transformation en format graphviz (responsable: Olivier)

- [x] Module countries

  - [x] Lecture du format jansson (responsable: Olivier)

- [x] Module input

  - [x] Lecture et vérification des entrées (responsable: Jean-Lou) 

- [x] Module output

  - [x] Intégration des modules input, countries et graphviz 
        afin d'afficher correctement(responsable: Jean-Lou)

- [x] Module exécutable

  - [x] Intégration de tous les modules afin de créer 
        un exécutable fonctionnel (responsable: Jean-Lou)

- [x] Module util

  - [x] Fonctions utiles n'appartenant pas à un module en particulier
        (responsable: Olivier)

- [x] Tests (responsables: Jean-Lou et Olivier)
  
  - [x] Tests Bats (responsables: Jean-Lou et Olivier)
  
  - [x] Tests CUnit (responsable: Olivier)
   
  - [x] Intégration continue (responsables: Olivier et Jean-Lou)


- [x] Autres

  - [x] Makefile (responsables: Jean-Lou et Olivier)

  - [x] Respect de la structure des répertoires (responsable: Jean-Lou)

  - [x] Documentation et README (responsables: Jean-Lou et Olivier)
