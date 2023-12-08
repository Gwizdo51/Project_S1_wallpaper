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

- Pose de papier peint
    - Les tailles de papier peint sont-elles fixes ? -> On peut imaginer un fichier "BDD.txt" qui listerait les différentes tailles de papier peint disponible, et laisser l'utilisateur choisir.
        - pas de gestion de stocks - tailles standards qui existent, mais tailles bizarres possibles -> les 2, sans exigence
    - Faut-il aussi mettre du papier peint sur la mansarde (~plafond) ?
        - mur toujours plan -> alignement non necessaire entre mur penché
    - Sens d'application du papier peint: vertical, horizontal ?
        - papier vertical
    - Faut-il aligner les motifs d'un mur à l'autre dans une même pièce ?
        - alignement sur les angles
    - Laisser la possibilité de mettre différents papiers peints sur un même mur ?
        - risque d'usine à gaz - Si on peut sans usine à gaz, sinon pas de changement de papier peint
    - Faut-il réutiliser les pertes sur d'autres murs ?
        - réutiliser tous les petits bouts, pas une bonne idée -> essayer de réuitliser les chutes de plus de 1m

- Mesures
    - Rapporteur disponible ? -> mesure d'angle par l'utilisateur ?
        - pas de rapporteur
    - Quelles unités pour les distances ? On laisse le choix ? On fixe à des mètres ?
        - à nous de trouver une solution élégante -> que sera le mieux pour l'utilisateur -> peut-être que le mètre ?
    - Quels types de formes de mur ? Polygones complètement aléatoires, ou on se limite a des hauts-de-pignons et sous-pentes ?
        - mur rectangle, avec éventuellement des mansardes

- Colle
    - Comment poser la colle ? Sur tout le papier peint ?
        - tout le papier peint, 2mm -> suivre le prompt
    - Comment la colle est conditionnée ? Pots ? Eau + poudre ? -> Retourner une quantité de pots de colle plutôt qu'un volume ?
        - volume de colle nécessaire -> préciser si on veut le volume brut (diviser par le volume d'un pot), et si en poudre, ratio de dissolution, on peut obtenir le nombre de sacs

- Fenêtres
    - Quelles formes de fenêtres à retirer: carré, rectangulaire, circulaire, polygone quelconque ... ?
        - fenêtres rectangulaires
    - Fenêtre et motifs: comment aligner les motifs si la fenêtre est énorme ?
        - /!\ attention avec les chutes de moins de 1m, on peut les réutiliser avec une grande fenêtre /!\

- Livrable
    - Y a-t-il besoin d'une interface graphique, avec des boutons etc ? (V2)
        - pas destiné à des informaticiens, donc plutôt oui, mais sans pression (si c'est possible)
    - se rappeler des derniers résultats ? -> donner des noms, une bdd historique ? (V2)
        - plutôt une super calculatrice, mais si on peut ressortir des projets précédents c'est mieux -> peut-être V2 ? -> voir comment l'implémenter dans le projet déjà fini, concevoir les branchements
    - Qui utilisera le logiciel ? -> le patron ou les techniciens (qtté de contrôle sur l’application) ? (V2)
        - service achat qui devrait se servir du logiciel
