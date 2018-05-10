#include <stdio.h>
#include <stdlib.h>
//Type Pile
typedef struct cellule
{
    int valeur;
    struct cellule *suivant;
} Cellule;

typedef Cellule * Pile;

Pile creerPile();

int estVide(Pile p);

void empiler(Pile *p, int x);

void depiler(Pile *p);

int sommet(Pile p);

void afficher(Pile p);
int egalite(Pile p1, Pile p2);

int main()
{
	Pile maPile1,maPile2;
    maPile1=creerPile();
    maPile2=creerPile();
    int i;
    empiler(&maPile2,5);
    for(i=0; i<50; i+=3)
    {
        empiler(&maPile1,i);
        empiler(&maPile2,i);
	}
	
	printf("la pile 1 \n");
	afficher(maPile1);
	
	printf("la pile 2 \n");
	afficher(maPile2);
	
	if (egalite(maPile1,maPile2)==1)
		printf("identique");
		else
		printf("NON !!!");
	
	
    return 0;
}

void afficher(Pile p) {
    Pile tmp;
    tmp = creerPile();
    if(estVide(p)){
        printf("La pile est vide!\n");
    }
    else{
        while(!estVide(p)){
            printf("%d\n",sommet(p));
            empiler(&tmp,sommet(p));
            depiler(&p);
        }
        while(!estVide(tmp)){
            empiler(&p,sommet(tmp));
            depiler(&tmp);
        }
    }
}


Pile creerPile()
{
    return NULL;
}

int estVide(Pile p) {
    return p==NULL;
}

void empiler(Pile *p, int x) {
    Cellule *nouv;
    nouv = (Cellule *)malloc(sizeof(*nouv));
    nouv->valeur=x;
    nouv->suivant=*p;
    *p=nouv;
}

void depiler(Pile *p) {
    if(!estVide(*p)){
    Pile ancien;
    ancien = *p;
    *p = (*p)->suivant;
    free(ancien);
    }
    else
        printf("La pile est dÃ©jÃ  vide!\n");
}

int sommet(Pile p) {
    return p->valeur;
}



int egalite(Pile p1, Pile p2)
{
	Pile maPile1,maPile2;
	int test=0;
	maPile1=creerPile();
	maPile2=creerPile();
	if(estVide(p1) && estVide(p2)){
        printf("La pile est vide!\n");
    }
    
    
    while(!estVide(p1) && !estVide(p2))
    {
		if(sommet(p1)!=sommet(p2))
		test=0;
		else
		{
			empiler(&maPile1,sommet(p1));
			empiler(&maPile2,sommet(p2));
			depiler(&p1);
			depiler(&p2);
			test=1;
		}
	}
	
	if( (estVide(p1) && !estVide(p2)) || (!estVide(p1) && estVide(p2)) )
	test=0;
	
	while(!estVide(maPile1) && !estVide(maPile2))
    {
			empiler(&p1,sommet(maPile1));
			empiler(&p2,sommet(maPile2));
			depiler(&maPile1);
			depiler(&maPile2);
	}
	return test;
}
	
	
		
    
    

	
