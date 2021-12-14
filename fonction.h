#include <gtk/gtk.h>
struct etudiant{

char nom[20];
char prenom[20];
char cin[20];
char chambre[20];
};
 struct etudiant ET;

int verifier(char log[],char Pw[]);
int rech (int NumRech);
void ajouter();
void rechercher();
void supprimer();
void modifier();
void afficher(GtkWidget *liste);

