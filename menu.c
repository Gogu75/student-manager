#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "Student.h"

void menu() {

    int choice = 1;
    int size = 0;
    int id = 0;

    Student **arrayStudent;
    arrayStudent = (Student **) malloc(sizeof(Student*));

    printf("----------------BIENVENUE SUR LE GESTIONNAIRE D'ELEVES---------------- \n");
    printf ("1> Ajouter un eleve \n");
    printf ("2> Afficher la liste des eleves \n");
    printf ("3> Supprimer un eleve \n");
    printf ("4> Ajouter une note \n");
    printf ("5> Afficher le detail d'un eleve \n");
    printf ("6> Modifier un eleve \n");
    printf ("7> Quitter le programme \n");

   do {

      printf ("Votre choix : \n");
      scanf ("%d", &choice);

      if (choice <= 0 || choice > 7) {
        printf ("La saisie est invalide.\n");
      }

      else if(choice == 1){
            addStudent(arrayStudent,size,id);
            size++;
            id++;
      }
      else if(choice == 2){
            printStudents(arrayStudent,size);
      }
      else if(choice == 3){
            deleteStudent(arrayStudent,size,id);
            size--;
      }
      else if(choice == 4){
            addMark(arrayStudent,size);
      }
      else if(choice == 5){
            detailsStudent(arrayStudent,size,id);
      }
      else if(choice == 6){
            updateStudent(arrayStudent,size,id);
      }
      else if(choice == 7){
          printf("Vous quitter le programme... \n");
          exit(0);
      }

   } while (choice != 7);

}
