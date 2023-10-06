# Définitions

- **pan coupé**: Le pan-coupé est un pan de mur qui remplace théoriquement l'angle qu'aurait formé la rencontre de deux murs
- **sous-pentes**: plafond penché (les combles)
- **hauts de pignons**: partie triangulaire d'un mur qui permet d'obtenir les versants d'un toit

# Comment communiquer les côtes au programme de manière claire ?

1. Entrer des patrons de pièces traiter tous les murs d'une manière uniforme
2. placer les points par rapport à un repère ? -> définir un point **O** (par ex. le coin en bas à gauche), et créer les points en fonction de leur position par rapport à l'origine ? (entrer direction + distance, le dernier point entré se rejoint à **O**)<br>
=> peut-être un peu trop mathématique pour l'utilisateur ?
3. Juste retirer des triangles à des rectangles -> retirer des pans de murs triangulaires à un mur de base rectangle ? -> pourra simplifier l'utilisation du programme, mais peut trop généraliser sur la forme d'un mur

# Questions

- pose de papier peint
    - Faut-il aussi mettre du papier peint sur la mansarde (~plafond) ?
    - Sens d'application du papier peint: vertical, horizontal, avec un angle qu'on laisserait l'utilisateur entrer ?
    - Les tailles de papier peint sont-elles fixes ? -> On peut imaginer un fichier "BDD.txt" qui listerait les différentes tailles de papier peint disponible, et laisser l'utilisateur choisir
    - Faut-il aligner les motifs d'un mur à l'autre dans une même pièce ?
    - Laisser la possibilité de mettre différents papiers peints sur un même mur ?
    - Faut-il réutiliser les pertes sur d'autres murs ?
- mesures
    - Rapporteur disponible ? -> mesure d'angle par l'utilisateur ?
    - Quelles unités pour les distances ? On laisse le choix ? On fixe à des mètres ?
    - Quels types de forme de mur ? Polygones complètement aléatoires, ou on se limite a des hauts-de-pignons et sous-pentes ?
- colle
    - Comment poser la colle ? Sur tout le papier peint ?
    - Comment la colle est conditionnée ? Pots ? Eau + poudre ? -> Retourner une quantité de pots de colle plutôt qu'un volume ?
    - Faut-il proposer différentes quantité de colle ?
- fenêtres
    - Quelles formes de fenêtres à retirer: carré, rectangulaire, circulaire, polygone quelconque ... ?
    - Taille de fenêtre
    - Fenêtre et motifs: comment aligner les motifs si la fenêtre est énorme ?
- livrable
    - Y a-t-il besoin d'une interface graphique, avec des boutons etc ?
    - se rappeler des derniers résultats ? -> donner des noms, une bdd historique ?
    - Qui utilisera le logiciel ?
