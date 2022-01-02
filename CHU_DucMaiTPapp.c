#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Member
{
    int id;
    char nom[30];
    char prenom[30];
    int age;
}Mb;


struct Node{
    Mb data;
    struct Node* Left;
    struct Node* Right;
};

typedef struct Node NODE;

typedef NODE* TREE;

//Comparer 2 données
int Compare(Mb x, Mb y)
{
    return strcmp(x.id, y.id);
}

//La fonction permet d'entrez des données
Mb inputItem()
{
    Mb x;
    int id;
    printf("\nEntrez l'id du membre (Q to quit) : ");
    gets(id);
    if(strcmp(x.id,"q")==0 ||strcmp(x.id,"Q")==0 ){
        return x;
    }
    printf("\nEntrez le nom du membre: ");
    gets(x.nom);
    printf("\nEntrez le prénom du membre :");
    gets(x.prenom);
    printf("\nEntrez l'age du membre: ");
    scanf("%d",&x.age);

    while (getchar() != '\n');
    return x;

}

//la fonction permet d'afficher des données d'un membre.
void outItem(Mb x)
{
    prinf("\n%d %s %-30s %d", x.id, x.nom, x.prenom, x.age);
}

//la fonction permet d'afficher les informations dans l'ordre des clés croissantes;
void LNR(TREE t) {
    if (t != NULL) {
        LNR(t->Left);
        outItem(t->data);
        LNR(t->Right);
    }
}

//La fonction permet de insérer une node x dans l'arbre binaire.
void InsertNode(TREE &t, Mb x)
{
    if(t!=NULL){
        if(Compare(t->data,x)==0)
            return -1;
        if(Compare(t->data, x)>0)
            return InsertNode(t->Left,x);
        else if(Compare(t->data,x)<0)
            return InsertNode(t->Right, x);
    }
    t=(NODE*)malloc(sizeof(NODE));
    if(t==NULL)
        return 0;
    t->data=x;
    t->Left=t->Right=NULL;
    return 1;
}

//Créer 1 arbre
void creerArbre(TREE &t)
{
    Mb x;
    while (1){
        printf("-- Entrez les données du membre --");
        x=inputItem();
        if(strcmp(x.id, "q")==0 || strcmp(x.id,"Q")==0)
            break;
        int check InsertNode(t, x);
        if(check ==-1)
            printf("Le membre n'existe pas!");
        else if(check==0)
            printf("Mémoire pleine");
        else printf("--Succes--\n");
    }
}



//La fonction permet de rechercher les informations correspondant à une clé donnée.
TREE rechercher(TREE t, int id)
{
    NODE *P=t;
    if(t!=NULL){
        if(t->data.id==id){
            return P;
        }
        else if(t->data.id>id)
            return rechercher(t->Left,id);
        else
            return rechercher(t->Right,id);
    }
    return NULL;
}


//La fonction permet de supprimer les données du membre x;
int supprimer(TREE &t, Mb x)
{
    if(t==NULL)
        return 0;
    else if(Compare(t->data, x)>0)
        return supprimer(t->Left,x);
    else if(Compare(t->data,x)<0)
        return supprimer(t->Right,x);
    else
    {
        NODE *p=t;
        if(t->Left==NULL)
            t=t->Right; //si node n'a qu'un sous-arbre à droit.
        else if(t->Right ==NULL)
            t=t->Left; // si node n'a qu'un sous-arbre à gauche.
        else //si node a tous les deux .
        {
            NODE *s=t, *q=s->Left;
            //lorsque s est le parent de q, q est le nœud le plus à droite du sous-arbre gauche de p.
            while (q->Right !=NULL)
            {
                s=q;
                q=q->Right;
            }
            p->data=q->data;
            s->Right=q->Left;
            delete q;
        }
    }
    return 1;
}

//La fonction permet de écrire des données dans la file txt.
void  writeFile(char *filename, TREE &t)
{
	if (t != NULL)
	{

		FILE *f = fopen(filename, "ab");
		fprintf(f, "%d\n", T->data.id);
		fprintf(f, "%s\n", T->data.nom);
		fprintf(f, "%s\n", T->data.prenom);
		fprintf(f, "%d\n", T->data.age);
		writeFile(filename, T->Left);
		writeFile(filename, T->Right);
		fclose(f);
	}
}

//La fonction permet de lecture des données à partir d'un file txt.
void readFile(char *filename, TREE &t)
{
	Mb x;
	FILE *f = fopen(filename, "r");
	if (f != NULL)
	{

		while (!feof(f))
		{
			fscanf(f, "%d\n", &x.id);
			fscanf(f, "%s\n", &x.nom);
			fscanf(f, "%s\n", &x.prenom);
			fscanf(f, "%d\n", &x.age);
			InsertNode(T, x);
		}
		fclose(f);
	}
	else
	{
		printf("--La liste des membres sont vide, Veuillez entrer un membre--\n");
		creerArbre(t);
	}

}



void Menu(TREE &t){
    char *f="BST.txt";
    while(true){
        printf("\n-------------------MENU-------------------");
        printf("\n1. Afficher dans l'ordre des clés croissants");
        printf("\n2.Rechercher");
        printf("\n3.Ajouter");
        printf("\n4.Supprimer");
        printf("\n5.Enregistrer des données")
        printf("\n0. Finir!!");
        int choix;
        printf("\nQu'est ce que vous voulez faire ?");
        scanf("%d", &choix);
        if(choix>5 || choix<0){
            printf("\nSélection non valide. ");
        }
        else if(choix==1){
            char f;
            printf("\n--Afficher dans l'ordre des clés croissants-- ")
            LNR(t);
            printf("------------------------------------------------");
            printf("\n r.Retourner à Menu");
            scanf("%s",&f);
            if(f=='r' || f=='R')
                goto Menu;
        }
        else if (choix==2){
            int id;
            printf("Entrez l'id du membre que vous chercher ? ");
            scanf("%d",&id);
            TREE P=rechercher(P,id);
            if(P!=0){
               printf("----------Trouvé le membre %d----------", id);
               outItem(P->data);
            }
            else {
                printf("Le membre n'existe pas !!");
                system("pause");
            }
            goto Menu;

        }
        else if(choix==3){
            creerArbre(t);
            goto Menu;
        }
        else if(choix==4){
            int id;
            printf("Saisie l'id du membre que vous voulez supprimer.\n");
            scanf("%d",&id);
            TREE P=rechercher(t, id);
            if(P!=NULL)
            {
                int del=1;
                while(del)
                {
                    if(P!=NULL){
                        printf("Suppression réussie!");
                        del=supprimer(t, P->data.id);
                    }
                    else
                    {
                        printf("Pas de données.");
                        del=0;
                    }
                }
                system("pause");
                goto Menu;
            }
        }
        else if (choix==5){
            writeFile(f, t);
            printf("Déjà enregistrer des données.");
            getch();
            goto Menu;
        }
        else
            break;
    }
}


int main(){
    TREE t;
    t=NULL;
    char *f="C:\\L1_LangageC\\TPLangageC\\TP_BST_CHU_DucMai\\BST.txt";
    printf("---------------Programme de gestion des membres---------------");
    readFile(f, t);
    Menu(t);
    system("pause");
    return 0;

}
