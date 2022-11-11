## _C++ Assembleur_

Pour améliorer mes compétences dans le langage C++, j'ai décidé de créer un petit assembleur, il est actuellement en cours de création et se sera finit bientôt :-) 


*Voici les différentes commandes implémenter actuellement :*

* Convertion
  * &"numero registre" !"nombre décimal" --> Convertie un nombre decimal dans un registre
* Affichage 
  * &"numero registre" --> Affiche un registre
  * &"numero registre" ! --> Affiche un registre en decimal
  * ls --> Affiche les commandes
* Calcul 
  * &"numero registre" &"numero registre" 01 &"numero registre" --> Addition
  * &"numero registre" &"numero registre" 02 &"numero registre" --> Soustraction
  * &"numero registre" &"numero registre" 03 &"numero registre" --> Multiplication
* Réinitialisation
  * *"numero registre" --> Reinitialise le registre
  * ** --> Reinitialise les registres
* Aléatoire
  * // --> Tout les registres aleatoire
  * /[<numero registre>] --> mets le registre aleatoire
* MEMORY
  * '~' devant une commande --> enregistre la commande dans une memoire
  * ~~ --> compile la commande
  * changement pour ces variables
  * &[<numero registre>] @[<nombre binaire>] --> Convertie un nombre binaire dans un registre
  * Convertion un nombre decimal dans un registre n'est pas disponible dans la memory
* TERMINAL
  * /clear --> Clear le terminal
  * help --> affiche les commandes
  * &/& --> Arret
