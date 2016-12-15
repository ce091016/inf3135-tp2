Correction du TP2
~~~~~~~~~~~~~~~~~

Étudiants
=========

- Jean-Lou Hallée (HALJ05129309)
- Olivier Levasseur (LEVO19109301)

Résultat
========

+-------------------------+-----------------------------+-----------+-----------+
| Critère                 | Description                 | Note      | Sur       |
+=========================+=============================+===========+===========+
|                         | Affichage des informations, |           |           |
|                         | traitement des arguments,   |           |           |
| Fonctionnabilité        | lecture du format JSON,     | 58        | 60        |
|                         | écriture au format dot,     |           |           |
|                         | appel de Graphviz, etc.     |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Style et documentation,     |           |           |
| Qualité du code         | décomposition modulaire,    | 28        | 30        |
|                         | encapsulation, etc.         |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Respect du format Markdown, |           |           |
| Fichier README          | qualité du contenu, tâches  | 29        | 30        |
|                         |                             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Compilation, nettoyage,     |           |           |
| Makefile                | mise à jour de la base de   |           |           |
|                         | données                     | 20        | 20        |
|                         | (``make``, ``make clean``,  |           |           |
|                         | ``make data``)              |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | Qualité de la couverture,   |           |           |
| Tests                   | utilisabilité, lisibilité,  | 20        | 30        |
|                         | fonctionnabilité            |           |           |
|                         | (``make test``)             |           |           |
+-------------------------+-----------------------------+-----------+-----------+
|                         | *Commits* liés à une tâche  |           |           |
| Utilisation de Git      | spécifique, message clair   | 28        | 30        |
|                         | et pertinent, gestion d'un  |           |           |
|                         | sous-module, collaboration, |           |           |
|                         | etc.                        |           |           |
+-------------------------+-----------------------------+-----------+-----------+
| **Total**                                             | **193**   | **200**   |
+-------------------------+-----------------------------+-----------+-----------+

Commentaires
============

- La compilation se complète sans avertissement et sans erreur sur Malt.
  Étrangement, sur MacOS, il y a un problème avec CUnit (qui fonctionne
  pourtant dans d'autres contextes... très étrange).
- Toutes les fonctionnalités semblent correctes sur Malt, mais il y a des
  problèmes bizarres sur MacOs. Bref, il y a un bogue subtil dans votre
  programme qui ne paraît pas sur Malt. Par exemple, voici ce que j'obtiens :

  .. code:: bash

      $ bin/tp2 --region Europe
      Invalid region.
      $ bin/tp2 --region europe
      Invalid region.

  Mon impression est que vous faites des opérations non sécuritaires sur les
  chaînes de caractères, mais c'est le genre de bogue difficile à détecter.
- La qualité du code est bonne en général. Les docstrings sont soignées et le
  programme est modulaire. Peut-être aligner davantage la description des
  paramètres dans les docstrings, pour améliorer la lisibilité. Ne pas oublier
  de supprimer les commentaires "inutiles" lors de la remise finale. Aérer
  davantage autour des opérateurs.
- Le fichier README est très bien. Éviter les indentation complètes du code (le
  premier niveau devrait être aligné à gauche avec le texte).
- Makefile générique, mais inutilement compliqué (pas de pénalité).
- Bonne couverture de tests, avec Bats et CUnit. Bonne configuration du fichier
  ``.gitlab-ci.yml``.
- Bonne utilisation de Git, sauf le fichier ``.gitignore`` qui devrait
  minimalement ignorer l'exécutable et même les fichiers ``.png``. Bonne
  synergie d'équipe.
