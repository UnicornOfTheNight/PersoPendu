#include "main.h"

int main(int argc, char* argv[])
{
    /* Initialisation des variables */
    char maLettre = ' ', motSecret[TAILLE_MAX] = {0}, lettresProposees[25]={0}, pendu[50] = {0};
    char* motcache = NULL;
    int conditionTest = 0, cptFautes = 0, cptAlphabet = 0, testLettresProposees = 0;

    if (!ChoisirMotHasard(motSecret)) //on appelle la fonction pour piocher un mot au hasard
        exit(0);

    int longueurMotSecret = strlen(motSecret);

    /* Allocation */
    motcache = malloc(longueurMotSecret * sizeof(char)); // On alloue de la mémoire pour le tableau
    if (motcache == NULL)// On vérifie si l'allocation a marché ou non
        exit(0);


    for(int i = 0; i < longueurMotSecret; i++)
        motcache[i] = '.'; //on remplace les lettres par des points

    motcache[longueurMotSecret] = '\0'; //On arrete la chaine

    printf("--- PENDU ---\n");

    while(conditionTest != longueurMotSecret && cptFautes < 8) //Tant que toutes les lettres ne sont pas trouvees et si il n'y a pas 8 fautes
    {
        printf("\nLETTRES DEJA PROPOSEES : %s", lettresProposees);

        printf("\nMOT : %s\n", motcache); //On affiche le mot caché

        printf("\nENTREZ UNE LETTRE : "); //On demande a l'utilisateur d'entrer une lettre
        maLettre = lireCaractere(); //On lit la lettre

        for(int i = 0; i < longueurMotSecret; i++) //on parcours le mot lettre une par une
        {
            if(motSecret[i] == maLettre && maLettre != motcache[i]) //si la lettre du mot correspond a la lettre entree et qu'elle n'est pas déjà affichée
            {
                motcache[i] = maLettre;
                conditionTest++;
            }
        }

        testLettresProposees = 0;

        /* GESTION DES LETTRES PROPOSEES */
        for(int i = 0; i<strlen(lettresProposees);i++){ //On parcours les lettres déjà proposées
            if(lettresProposees[i] == maLettre) // Si la lettre entrée a déjà été proposée
                testLettresProposees = 1; //le test prend 1
        }

        if(testLettresProposees == 0){//si la lettre entree n'a jamais été proposée
            lettresProposees[cptAlphabet] = toupper(maLettre); //on la rajoute au tableau
            cptAlphabet++;
        }

        for(int f = 0; f<strlen(motcache); f++){ //On parcourt le mot caché
            if (maLettre == motcache[f]){ //Si la lettre entree a deja ete affichee
                testLettresProposees = 1; //Le test prend 1
            }
        }

        /* GESTION DU COMPTEUR DE FAUTES */
        if(testLettresProposees == 0)
            cptFautes++;

        switch(cptFautes){
            case 0 :
                sprintf(pendu, "   ");
                break;

            case 1 :
                sprintf(pendu, "---");
                break;

            case 2 :
                sprintf(pendu, " |\n |\n |\n |\n |\n---");
                break;

            case 3 :
                sprintf(pendu, "  ___\n |\n |\n |\n |\n |\n---");
                break;

            case 4 :
                sprintf(pendu, "  ___\n |   |\n |\n |\n |\n |\n---");
                break;

            case 5 :
                sprintf(pendu, "  ___\n |   |\n |   O\n |\n |\n |\n---");
                break;

            case 6 :
                sprintf(pendu, "  ___\n |   |\n |   O\n |   |\n |\n |\n---");
                break;

            case 7 :
                sprintf(pendu, "  ___\n |   |\n |   O\n |  -|-\n |\n |\n---");
                break;

            case 8:
                sprintf(pendu, "  ___\n |   |\n |   O\n |  -|-\n |  / \\\n |\n---");
                break;

        }

        printf("\n%s\n", pendu);
    }

    /* RESULTATS */
    if(cptFautes == 8)
        printf("\nPERDU, LE MOT ETAIT %s", motSecret);
    else
        printf("\nBRAVO!\nLe mot etait bien %s\n", motSecret);

    free(motcache);

    return 0;
}
int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}

int ChoisirMotHasard(char* motPioche){

    /* DECLARATION DES VARIABLES */
    FILE* fichier = NULL;
    fichier = fopen("Dictionnaire.txt", "r"); //On ouvre le fichier en lecture
    int compteurLignes = 0, nbHasard = 0, caractereActuel = 0, nbCaracteres = 0;

    if(fichier == NULL){
        printf("Impossible d'ouvrir le fichier.");
        return 0;
    }

    do
    {

        caractereActuel = fgetc(fichier); // On lit le caractère
        if(caractereActuel == '\n' )
                compteurLignes++; //Pour connaitre le nombre de lignes

    } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)

    nbHasard = nombreAleatoire(compteurLignes);

    rewind(fichier); //On se repplace au debut du fichier

    while (nbHasard>0){ // Pour se placer devant le bon mot
        caractereActuel = fgetc(fichier);

        if(caractereActuel == '\n')
            nbHasard--;

    }

    fgets(motPioche, 100, fichier); //On recupere le mot

    motPioche[strlen(motPioche) - 1] = '\0'; //On remplace le \n

    fclose(fichier);

    return 1;
}
