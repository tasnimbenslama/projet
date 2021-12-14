#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
 ECIN,
 ENOM,
 EPRENOM,
 ECHAMBRE,
 COLUMNS,
};
void supprimer(char cin[])
{

struct etudiant ET;

FILE *f,*g;
f=fopen("etudiant.txt","r");
g=fopen("users.txt","a");
if(f!=NULL || g!=NULL ){
	do
{
	fscanf(f,"%s %s %s %s ",ET.cin,ET.nom,ET.prenom,ET.chambre);

if(strcmp(ET.cin,cin)!=0)
{
fprintf(g,"%s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre);
        }
}while(!feof(f));

fclose(g);
fclose(f);
remove("etudiant.txt");
rename("users.txt","etudiant.txt");
}
}
int verifier(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}


void afficher(GtkWidget *liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
char chambre[20];
store=NULL;


FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{	renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();					   	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();	
column=gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",ECHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();								   	
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("etudiant.txt","r");
if(f==NULL)
{
return;
}
else{
	f=fopen("etudiant.txt","a+");
	while(fscanf(f,"%s %s %s %s \n",cin,nom,prenom,chambre)!=EOF)
	{gtk_list_store_append(store, &iter);
									gtk_list_store_set(store,&iter,ECIN,cin,ENOM,nom,EPRENOM,prenom,ECHAMBRE,chambre );
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
}

}
void modifier(struct etudiant ET)
{
/*struct etudiant ET;*/

FILE *f,*g;
char ch1[20],ch2[20],ch3[20],ch4[20];
f=fopen("etudiant.txt","r");
g=fopen("users.txt","a");
if(f==NULL || g!=NULL )
do{
fscanf(f,"%s %s %s %s ",ch1,ch2,ch3,ch4);/*!=EOF*/
if 
(strcmp(ET.cin,ch1)!=0)
{
fprintf(g,"%s %s %s %s \n",ch1,ch2,ch3,ch4);
}else 
fprintf(g,"%s %s %s %s \n",ET.cin,ET.nom,ET.prenom,ET.chambre);
}while(!feof(f));
fclose(g);
fclose(f);
remove("etudiant.txt");
rename("users.txt","etudiant.txt");
}
