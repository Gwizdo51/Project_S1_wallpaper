# Commandes GIT

## Commandes de base

- `git clone <repo_url_link>` : clone le repo depuis le cloud dans un dossier local
- `git fetch` : mettre à jour les références du cloud
- `git status` : comparer les changements entre le dossier local et le dernier commit
- `git pull` : mettre à jour le dossier local ("tirer" les changements du cloud)
- `git add <files_to_add>` : ajouter les changements pour un nouveau commit
- `git reset` : annuler `git add`
- `git commit -m "<commit_message>"` : faire un nouveau commit (une nouvelle photo)
- `git push` : mettre à jour le repo dans le cloud ("pousser" ses commits dans le cloud)

## Branches

- `git branch -a` : afficher toutes les branches (locales et distantes)
- `git branch <new_branch_name>` : créer une nouvelle branche en local
- `git switch <branch_name>` : changer de branche active
- `git push -u origin <new_branch>` : ajouter la branche sur le repo distant (avec tracking entre les branches locale et distante)

# To do list

- Côté Calcul :
    - [ ] Trouver le calcul qui permet de définir les rouleaux à acheter.
    - [ ] Trouver le calcul qui permet de déterminer la côte.
    - [ ] Trouver le calcul qui retire les fenêtre.
    - [ ] Trouver le calcul qui donne la quantité de colle à acheter.

# Initialisation

- Ce qu'il faut faire principalement:
    - [ ] Spécification (Tableau de problématiques + Solutions).
    - [ ] Maquette fonctionnelle.
    - [ ] Schéma fonctionnelle.
    - [ ] Cahier des charges.

# Project_S1_wallpaper

- Faire un logiciel Pc :
    - Ce dernier permet de quantifier les mattériaux à commander.
    - Faciliter le cliens sur tout les plans calcul.
    - Déterminer le prix total à payer.

- Fonctionnement :
    - Saisir les différents côtes des différents mûrs.
    - Saisir longueur du motif sur le papier peint.
    - Saisir les dimmensions d'obstacle présent sur un mûr
    - Saisir les plans coupés.
    - L'application effectue le calcul
    - Le résultat du calcul s'affiche et indique également la quantité de colle à acheter.

# Idées V2

- Historique de projets
- BDD de rouleaux disponibles
- Interface graphique dynamique (avec des boutons et tt)
- changement d'unité
- différents papiers peints (mélange motifs et uni)
- changement de langue
- laisser le choix d'utiliser différent papier peints
