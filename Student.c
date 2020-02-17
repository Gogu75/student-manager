#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"

void addStudent(Student **arrayStudent, int size, int id) {

    arrayStudent = realloc(arrayStudent, sizeof(Student*)*(size+1)); //on réallou le tableau pour rajouter des étudiants

    Student *newStudent;
    newStudent = malloc(sizeof(Student)); //on alloue la structure


    char *nom = malloc(sizeof(char)*51);            //on alloue chaque éléments de la structure
    char *prenom = malloc(sizeof(char)*51);
    char *promotion = malloc(sizeof(char)*51);

    printf("Indiquez le prenom de l'eleve : \n");
    fflush(stdin);
    fgets(prenom, 50, stdin);
    if(strlen(prenom) < 50) {
        prenom[strlen(prenom)-1] = '\0';
    }
    printf("Indiquez le nom de l'eleve : \n");
    fflush(stdin);
    fgets(nom, 50, stdin);
    if(strlen(nom) < 50) {
        nom[strlen(nom)-1] = '\0';
    }
    printf("Indiquez la promotion de l'eleve : \n");
    fflush(stdin);
    fgets(promotion, 50, stdin);
    if(strlen(promotion) < 50) {
        promotion[strlen(promotion)-1] = '\0';
    }

    newStudent->id = id+1;
    newStudent->firstName = malloc(sizeof(char)*(strlen(prenom)+1));
    newStudent->lastName = malloc(sizeof(char)*(strlen(nom)+1));
    newStudent->promotion = malloc(sizeof(char)*(strlen(promotion)+1));
    newStudent->markCount = 0;

    strcpy(newStudent->firstName, prenom);
    strcpy(newStudent->lastName, nom);
    strcpy(newStudent->promotion, promotion);



    arrayStudent[size] = newStudent;

    free(prenom);
    free(nom);
    free(promotion);

}

void printStudents(Student **arrayStudent, int size) {
    if(size <= 0) {
        printf("Il n'y a pas d'etudiants \n");
    }
    printf("Voici les etudiants : \n");
    for(int i = 0; i < size; i++) {
        printf("Etudiant %d : %s %s %s \n", arrayStudent[i]->id, arrayStudent[i]->firstName, arrayStudent[i]->lastName, arrayStudent[i]->promotion);
    }

}


void deleteStudent(Student **arrayStudent, int size, int id) {

    printf("Entrez le numero d'identifiant a supprimer : \n");
    scanf("%d", &id);

    if(size <= 0) {
        printf("Il n'y a pas d'etudiants \n");
    }

    if(id < 0 || id > size) {
        printf("Identifiant non valide \n");
        exit(0);
    }

    for(int i = id; i < size; i++) { //parcourt du tableau depuis le numero d'ID
        arrayStudent[i-1] = arrayStudent[i]; //on décale tous les éléments vers la gauche
        free(arrayStudent[i]);
    }

     printf("Etudiant %d supprime \n", id);
     arrayStudent = realloc(arrayStudent, sizeof(Student*)*(size-1)); //on réalloue le tableau d'étudiants



}

void addMark(Student **arrayStudent, int size) {

    int bufferMarks;

    if(size <= 0) {
        printf("Il n'y a pas d'etudiants \n");
    }

    for(int i = 0; i < size; i++) {
        printf("Combien de notes voulez-vous saisir pour l'etudiant %d ? \n", arrayStudent[i]->id);
        scanf("%d", &bufferMarks);
        for(int j = 0; j < bufferMarks; j++) {
            printf("Notes %d : \n", j+1);
            scanf("%lf", arrayStudent[i]->marks + arrayStudent[i]->markCount + j);
        }
        arrayStudent[i]->markCount += bufferMarks;
    }
}

void detailsStudent(Student **arrayStudent, int size, int id) {

    double sum = 0;

    if(size <= 0) {
        printf("Il n'y a pas d'etudiants \n");
    }

    printf("Saisissez le numero de l'etudiant a consulter : \n");
    scanf("%d", &id);

    if(id < 0 || id > size) {
        printf("Identifiant non valide \n");
        exit(0);
    }

    for(int i = 0; i < size; i++) {
        if(arrayStudent[i]->id == id) {
            printf("Prenom : %s  \n", arrayStudent[i]->firstName);
            printf("Nom : %s \n", arrayStudent[i]->lastName);
            printf("Promotion : %s \n", arrayStudent[i]->promotion);
            printf("Note(s) %d : \n", arrayStudent[i]->markCount);
            for(int j = 0; j < arrayStudent[i]->markCount; j++) {
                printf("%.2lf \n", arrayStudent[i]->marks[j]);
                sum = sum + arrayStudent[i]->marks[j];
                arrayStudent[i]->average = sum / arrayStudent[i]->markCount;
            }

        }
        if(arrayStudent[i]->markCount > 0) {
            printf("Moyenne : %.2lf \n", arrayStudent[i]->average);
        } else if(arrayStudent[i]->markCount <= 0) {
            printf("Cet etudiant n'a pas encore de notes \n");
        }
    }
}

void updateStudent(Student **arrayStudent, int size, int id) {

    char *newFirstname = malloc(sizeof(char)*51);
    char *newLastname = malloc(sizeof(char)*51);
    char *newPromotion = malloc(sizeof(char)*51);

    double newMark;
    int markPosition = 0;
    int modif = 0;

    if(size <= 0) {
        printf("Il n'y a pas d'etudiants \n");
    }

    printf("Saisir le numero d'identifiant de l'etudiant a modifier \n");
    scanf("%d", &id);

    if(id < 0 || id > size) {
        printf("Identifiant non valide \n");
        exit(0);
    }

    printf("Que voulez-vous modifier ? (taper 1 pour le prenom, 2 pour le nom ou 3 pour la promotion ou 4 pour une note \n");
    scanf("%d", &modif);

    if(modif == 1) {
        printf("Rentrer le nouveau prenom : \n");
        fflush(stdin);
        fgets(newFirstname, 50, stdin);
        if(strlen(newFirstname) < 50) {
            newFirstname[strlen(newFirstname)-1] = '\0';
        }
    }

    else if(modif == 2) {
        printf("Rentrer le nouveau nom : \n");
        fflush(stdin);
        fgets(newLastname, 50, stdin);
        if(strlen(newLastname) < 50) {
            newLastname[strlen(newLastname)-1] = '\0';
        }
    }

    else if(modif == 3) {
        printf("Rentrer la nouvelle promotion : \n");
        fflush(stdin);
        fgets(newPromotion, 50, stdin);
        if(strlen(newPromotion) < 50) {
            newPromotion[strlen(newPromotion)-1] = '\0';
        }
    }

    else if(modif == 4) {
        printf("Quelle note voulez-vous modifier ? : \n");
        scanf("%d", &markPosition);
    }

    for(int i = 0; i < size; i++) {
        if(arrayStudent[i]->id == id) {
            if(modif == 1) {
                arrayStudent[i]->firstName = realloc(arrayStudent[i]->firstName, sizeof(char)*(strlen(newFirstname)+1));
                strcpy(arrayStudent[i]->firstName, newFirstname);
            } else if(modif == 2) {
                arrayStudent[i]->lastName = realloc(arrayStudent[i]->lastName, sizeof(char)*(strlen(newLastname)+1));
                strcpy(arrayStudent[i]->lastName, newLastname);
            } else if(modif == 3) {
                arrayStudent[i]->promotion = realloc(arrayStudent[i]->promotion, sizeof(char)*(strlen(newPromotion)+1));
                strcpy(arrayStudent[i]->promotion, newPromotion);
            } else if(modif == 4) {
                printf("Entrer la nouvelle note : \n");
                scanf("%lf", &newMark);
                for(int j = 0; j < arrayStudent[i]->markCount; j++) {
                    if(arrayStudent[i]->markCount == markPosition) {
                        arrayStudent[i]->marks[markPosition-1] = newMark;
                    }
                }
            }
        }
    }

    free(newFirstname);
    free(newLastname);
    free(newPromotion);
}
