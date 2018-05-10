
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

Pile decouper(Pile p, int i);



int main()
{
	int i,n;
	Pile maPile;
    maPile=creerPile();
    
    for(i=0; i<50; i+=3)
    {
        empiler(&maPile,i);
	}
	printf("la pile  avant \n");
	afficher(maPile); 
	printf("\n\n");
    
	printf("saisir n \n");
	scanf("%d",&n);
	
	printf("\n\n");
	
	
    
    printf("la pile apres \n");
	
	afficher(decouper(maPile,n));
	
	
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

Pile decouper(Pile p, int i)
{
	Pile tmp,res;
	tmp=creerPile();
	res=creerPile();
	
	while(!estVide(p))
	{
		empiler(&tmp,sommet(p));
		depiler(&p);
	}
	while(!estVide(tmp) && i>0)
	{
		empiler(&res,sommet(tmp));
		empiler(&p,sommet(tmp));
		depiler(&tmp);
		i--;
	}
	while(!estVide(tmp))
	{
		empiler(&p,sommet(tmp));
		depiler(&tmp);
	}
	return res;
}
	
		


	
	
		
    
    

	
