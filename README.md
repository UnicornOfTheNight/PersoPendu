# 😵 Perso Pendu (Hangman)

![Language](https://img.shields.io/badge/Language-C-blue)
![Type](https://img.shields.io/badge/Type-Console%20Game-lightgrey)
![Status](https://img.shields.io/badge/Status-Completed-green)

Une implémentation complète et robuste du jeu du **Pendu** en langage C. Ce projet console permet de deviner un mot caché tiré au hasard depuis un dictionnaire externe.

## 🎮 Description

Le joueur doit trouver un mot secret en proposant des lettres une par une.
* Chaque lettre trouvée est révélée dans le mot.
* Chaque erreur dessine une partie du pendu.
* Au bout de **8 erreurs**, la partie est perdue.



## ✨ Fonctionnalités Clés

* **Dictionnaire Externe** : Le jeu n'est pas limité à une liste fixe. Il lit les mots depuis un fichier `Dictionnaire.txt` (gestion d'entrées/sorties de fichiers).
* **Sélection Aléatoire** : Un mot est choisi au hasard à chaque lancement.
* **Gestion des doublons** : Le programme détecte si vous avez déjà proposé une lettre et ne vous pénalise pas.
* **Affichage ASCII** : Évolution visuelle du pendu étape par étape.
* **Insensible à la casse** : Gère les entrées minuscules/majuscules automatiquement.

## 🛠 Concepts Techniques Abordés

Ce projet met en pratique des notions avancées du C :
* **Allocation Dynamique** (`malloc` / `free`) : La mémoire pour le mot caché est allouée selon la longueur du mot pioché.
* **Pointeurs** : Manipulation de chaînes de caractères via des pointeurs (`char*`).
* **Manipulation de Fichiers** (`fopen`, `fgets`, `rewind`) : Comptage des lignes et extraction d'une ligne spécifique.
* **Chaînes de caractères** : Utilisation de `string.h` (`strlen`, `strcmp`).

## 🚀 Installation & Compilation

Pour jouer, vous devez compiler le code source et vous assurer d'avoir le fichier dictionnaire.

1.  **Cloner le dépôt :**
    ```bash
    git clone [https://github.com/UnicornOfTheNight/PersoPendu.git](https://github.com/UnicornOfTheNight/PersoPendu.git)
    cd PersoPendu
    ```

2.  **Préparer le Dictionnaire :**
    Assurez-vous qu'un fichier nommé `Dictionnaire.txt` est présent dans le même dossier que l'exécutable. Il doit contenir un mot par ligne (sans espaces).
    *Exemple de `Dictionnaire.txt` :*
    ```text
    ELEPHANT
    PROGRAMMATION
    ORDINATEUR
    GUITARE
    ```

3.  **Compiler :**
    ```bash
    gcc main.c -o pendu
    ```

4.  **Lancer :**
    * *Linux / Mac :* `./pendu`
    * *Windows :* `pendu.exe`

## 🖥️ Aperçu du Jeu

```text
--- PENDU ---

LETTRES DEJA PROPOSEES : A E I

MOT : P R O G R A . . A . I O N

ENTREZ UNE LETTRE : Z

   ___
  |   |
  |   O
  |  -|-
  |
  |
 ---
