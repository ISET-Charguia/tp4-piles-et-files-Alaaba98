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

int main()
{
    Pile maPile;
    maPile=creerPile();
    int i;
    for(i=0; i<20; i+=2)
        empiler(&maPile,i);
    afficher(maPile);
    if(!estVide(maPile))
        printf("Le sommet de la pile est %d\n",sommet(maPile));
    depiler(&maPile);
    afficher(maPile);
    return 0;
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
