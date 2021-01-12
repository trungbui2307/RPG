
/*  Game Description: ANTMAN est un jeu developpe pour le cours de Programmation C++.
    C'est un jeu d'action RPG avec ses graphismes 2D et sa vu aerienne.
    Le jeu a ete realise en utilisant C++ library et Allegro5.


 *  Comment jouer ?
    Vous controlez le mouvement du personnage <Guerrier> à ramasser des objets numerotes 1 -> 9.
    Chaqua objet vous donne des points de vies supplementaires.

        ARROWS: Se déplacer avec la direction correspondante
        W,A,S,D : casser des briques avec la direction correspondante

    A chaque fois vous ramassez un objet ramassable, vous gagnerez le point de vie et le capacite d'attaque * 2
    correspondante aux numeros indiques. Idem, Objet ramasse numero 7, vous gagnez 7 point de vie avec 14 capacite d'attaque.

    Une fois que vous arrivez a cote du ennemi et vous choissisez une direction vers l'ennemi, vous allez etre en duel avec l'ennemy.
    C'est-a-dire, vous l'attaquez et il vous attaque en retour. Le degat affecte est calcule comme suivant:
                    degat = capacite d'attaque - capacite defense ennemy.
    Donc, Pensez-vous a collecter des objets ramassable pour augmenter vos points de vie ainsi que le capacite d'attaque
    avant de provoquer l'ennemi.

 *  Installation Allegro5: Si vous avez rencontré des problèmes liés au lancement de l'application. Veuillez revérifier linker de Allegro5 ("Build Option")
			   dans le projet ou MinGW dans votre système d'exploitation. IDE utilisé pour le projet: CodeBlock::.

 *  Developpeurs:
    BUI Manh Trung(u21708514 - manh-trung.bui@etu.u-pec.fr)
    HO Thi Ngoc Anh(u21716137 - thi-ngoc-anh.ho@etu.u-pec.fr)

*/
