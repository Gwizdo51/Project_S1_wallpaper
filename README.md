# Projet de Développement - ESAIP - Bachelor numérique - S1 2023 - EAOA Progress

Ce dépôt github contient le code source du projet de tapissage de papier peint du 1er semestre 2023 du cursus de bachelor numérique de l'ESAIP.

## Installation

Il suffit de télécharger la dernière version de l'exécutable **wallpainter.exe** (cf. [releases](https://github.com/Gwizdo51/Project_S1_wallpaper/releases)).<br>

## Quick start

- Placer l'exécutable **wallpainter.exe** dans un dossier de travail de votre choix (les fichiers texte créés pour enregistrer les résultats seront placés au même endroit que l'exécutable)
- Exécuter le fichier, en double-cliquant dessus

## Manuel utilisateur + documentation

cf. [wiki](https://github.com/Gwizdo51/Project_S1_wallpaper/wiki)

## Compilation de wallpainter.exe

La compilation ne peut s'effectuer qu'avec le système d'exploitation **Windows 10** ou **11**.
1. Installer [MinGW](https://sourceforge.net/projects/mingw/)
2. Ajouter le chemin vers **gcc.exe** à votre variable d'environnement **PATH** ("MinGW\bin") ([Comment ajouter un dossier à sa variable d'environnement PATH](https://learn.microsoft.com/fr-fr/previous-versions/office/developer/sharepoint-2010/ee537574(v=office.14)))
3. Exécuter **compile.bat** en double-cliquant dessus

# DUMP

## Idées V2

- Historique de projets
- BDD de rouleaux disponibles
- Interface graphique dynamique (avec des boutons et tt)
- changement d'unité
- différents papiers peints (mélange motifs et uni)
- changement de langue
- laisser le choix d'utiliser différent papier peints

## Commandes GIT

### Commandes de base

- `git clone <repo_url_link>` : clone le repo depuis le cloud dans un dossier local
- `git fetch` : mettre à jour les références du cloud
- `git status` : comparer les changements entre le dossier local et le dernier commit
- `git pull` : mettre à jour le dossier local ("tirer" les changements du cloud)
- `git add <files_to_add>` : ajouter les changements pour un nouveau commit
- `git reset` : annuler `git add`
- `git commit -m "<commit_message>"` : faire un nouveau commit (une nouvelle photo)
- `git push` : mettre à jour le repo dans le cloud ("pousser" ses commits dans le cloud)

### Branches

- `git branch -a` : afficher toutes les branches (locales et distantes)
- `git branch <new_branch_name>` : créer une nouvelle branche en local
- `git switch <branch_name>` : changer de branche active
- `git push -u origin <new_branch>` : ajouter la branche sur le repo distant (avec tracking entre les branches locale et distante)
