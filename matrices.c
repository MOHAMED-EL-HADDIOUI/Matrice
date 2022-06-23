#include "matrices.h"
#include <assert.h>
#include <stdio.h> // printf,scanf,gets,getchar
#include <stdlib.h>//pour malloc ,calloc,realloc#include <math.h>
#include <math.h>
//_________________________________________________________________________________
//La création de matrice c'est-à-dire allow l'espace mémoire 
void  creerMatrice(matrice_t *ptrMat)
{

    double **p;
    //allocation
    ptrMat->mat=(double **)malloc(ptrMat->nl*sizeof(double *));  
    for(p=ptrMat->mat;p<ptrMat->mat+ptrMat->nl;p++)
    {

        *p=(double *)malloc(ptrMat->nc*sizeof(double ));
    
    }

}
//Saisir de matrice 
void scanMatrice( matrice_t *ptrMat)
{
    double **p,*q;
    printf("_________Nombre de lingnes :");
    scanf("%d",&ptrMat->nl);
    printf("_________Nombre de colones :");
    scanf("%d",&ptrMat->nc);
    creerMatrice(ptrMat);
    p=ptrMat->mat;
    q=*p;
    int i,j;
    for(i=0,p=ptrMat->mat;p<ptrMat->mat+ptrMat->nl;p++,i++)
    {
        for(j=0,q=*p;q<*p+ptrMat->nc;q++,j++)
        {
        printf("_____[%d][%d]= ",i,j);
        scanf("%lf",q);//Saisir le coefficient [ieme,jeme]
        }
    }
}
//Afficher de matrice 

void printMatrice(const matrice_t *ptrMat)//pour eviter une copie (lourde)
{
    double **p;
    double *q;
    printf("________________________________________________\n");
    printf("|                Les informations              |\n");
    printf("_________Nombre de lingnes : %d\n",ptrMat->nl);
    printf("_________Nombre de lingnes : %d\n",ptrMat->nc);
    printf("________________________________________________\n");
    printf("|                    Matrice                   |\n");
    int i,j;
    for(i=0,p=ptrMat->mat;p<ptrMat->mat+ptrMat->nl;p++,i++)
    {
        for(j=0,q=*p;q<*p+ptrMat->nc;q++,j++)
        {
        printf("[%d][%d]=%lf ",i,j,*q);//Afficher le coefficient [ieme,jeme]
        }
        printf("\n");
    }
    printf("________________________________________________\n");
}
//Calculer la somme du deux matrice
matrice_t add(const matrice_t *ptrMat1,const matrice_t *ptrMat2)
{
    matrice_t somme;
    double **p1,**p2,**p3;
    double *q1,*q2,*q3;
    assert(ptrMat1->nl==ptrMat2->nl && ptrMat1->nc==ptrMat2->nc );//il faut que ont même taille
    somme.nl=ptrMat1->nl;
    somme.nc=ptrMat1->nc;
    creerMatrice(&somme);
    int i,j;
    for (p1=ptrMat1->mat,p2=ptrMat2->mat,p3=somme.mat;p1<ptrMat1->mat+ptrMat1->nl;p1++,p2++,p3++)
    { for (q1=*p1,q2=*p2,q3=*p3;q1<*p1+ptrMat1->nc;q1++,q2++,q3++)
      {
          *q3=*q1+*q2;
      }
    }  
    return somme;
}


//______________________________________Question :1___________________________________________

//Calculer le produit du deux matrice
matrice_t produit(const matrice_t *prtMat1,const matrice_t *prtMat2)
{
    matrice_t produitM;
    double **p1,**p3,**p2;
    double *q1,*q2,*q3;
    int j;
    assert(prtMat1->nc==prtMat2->nl);//il faut que le nombre des colonnes de premiere matrice egale a le nombre des lignes de deuxmiere matrice
    produitM.nl=prtMat1->nl;//le nombre des lignes egale a le nombre des lingnes de premiere matrice
    produitM.nc=prtMat2->nc;//le nombre des colonnes egale a le nombre des colonnes de deuxieme matrice
    creerMatrice(&produitM);
    for(p3=produitM.mat,p1=prtMat1->mat;p3<produitM.mat+produitM.nl;p3++,p1++)
    {
    for (q3=*p3,j=0;q3<*p3+produitM.nc;q3++,j++)
    { 
      p2=prtMat2->mat;
      double somme=0;
    for (q1=*p1,q2=*p2;q1<*p1+prtMat1->nc;q1++,p2++)
    {
        q2=*p2;
        double w1,w2;
        w1=*q1;
        w2=*(q2+j);
        somme+=w1*w2;
    }
    *q3=somme;
    }
    
    }
    return produitM;
}
//______________________________________Question :2___________________________________________

//La création de vecteur c'est-à-dire allow l'espace mémoire 
void CreerVecteur(vecteur_t *ptrVect){
    ptrVect->vect=(double *)malloc(ptrVect->n*sizeof(double));  
}
//Saisir de vecteur 
void scanVecteur(vecteur_t *prtVect)
{
    double *q;
    printf("__________Les informaions__________\n");
    printf("_________Nombre de composantes :");
    scanf("%d",&prtVect->n);
    CreerVecteur(prtVect);
    q=prtVect->vect;
    int i;
    for(i=0,q=prtVect->vect;q<prtVect->vect+prtVect->n;q++,i++)
    {
        
        printf("_____[%d]= ",i);
        scanf("%lf",q);
       
    }

}
//Afficher de vecteur 

void printVecteur(const vecteur_t *ptrVect)
{

    double *q;
    printf("___________________________\n");
    printf("_________Vecteur_________\n");
    printf("_________Nombre de composantes :%d\n",ptrVect->n);
    printf("___________________________\n");
    printf("_________Les Valeurs_________\n");
    int i;
    for(i=0,q=ptrVect->vect;q<ptrVect->vect+ptrVect->n;q++,i++)
    {
        
        printf("[%d]=%2.lf ",i,*q);
        printf("\n");
    }
    printf("___________________________\n");

}
//Calculer La Multiplication entre une Matrice et un Vecteur

vecteur_t MatDotVect(const matrice_t *prtMat,const vecteur_t *prtVet)
{
    vecteur_t vecteur;
    double *q1,**p2;
    double *q2,*q3;
    int j;
    assert(prtMat->nc==prtVet->n);
    vecteur.n=prtMat->nl;
    CreerVecteur(&vecteur);

    for(q1=vecteur.vect,p2=prtMat->mat;q1<vecteur.vect+vecteur.n;q1++,p2++)
    { 
        double somme=0;
    for(q2=*p2,q3=prtVet->vect;q2<*p2+prtMat->nc;q2++,q3++)
      {
          double u;
        u=*q3;
        somme+=(*q2)*u;
      }
     *q1=somme;
    }
    return vecteur;
}
//______________________________________Question :3___________________________________________

//Determier le Diagonale d'une Matrice
vecteur_t getDiag(const matrice_t *ptr1){
	assert(ptr1->nc == ptr1->nl);//il faut que une Matrice carrée
    vecteur_t dia;
    dia.n=ptr1->nl;
    CreerVecteur(&dia);
    int i,j;
    assert(ptr1->nl==ptr1->nc);
    double **p,*r,*q;
    for(i=0,r=dia.vect,p=ptr1->mat;p<ptr1->mat+ptr1->nl;p++,i++,r++)
    {
        q=*p;
        *r=*(q+i);
    }
    return dia;
}
//______________________________________Question :4___________________________________________
//Determier le 2eme Diagonale d'une Matrice
vecteur_t get2emeDiag(const matrice_t *prtmatr)
{
    assert(prtmatr->nl==prtmatr->nc);//il faut que une Matrice carrée
    vecteur_t dia;
    dia.n=prtmatr->nl;
    CreerVecteur(&dia);
    int i,j;
    double **p,*r,*q;
    for(i=prtmatr->nl-1,r=dia.vect,p=prtmatr->mat;p<prtmatr->mat+prtmatr->nl;p++,i--,r++)
    {
        q=*p;
        *r=*(q+i);
    }
    return dia;
}
//______________________________________Question :5___________________________________________
//Le Transformer une Matrice en un Vecteur
vecteur_t Mat2Vect(const matrice_t *ptr1){
	vecteur_t v1;
	double **p1,*q1,*q3;
	v1.n=ptr1->nl*ptr1->nc;
	CreerVecteur(&v1);
	for(p1=ptr1->mat,q3=v1.vect;p1<ptr1->mat+ptr1->nl;p1++){	
        for(q1=*p1;q1<*p1+ptr1->nc;q1++,q3++){
            *q3=*q1;
        }
    }
    return v1;
}

//______________________________________Question :6___________________________________________
//Le Transformer un Vecteur en une Matrice
matrice_t Vect2Mat(const vecteur_t *vec,int nl){
    int n=vec->n;
    matrice_t matrice;
	double **p1,*q1,*q3;
	assert(n%nl==0);
    matrice.nl=nl;
    matrice.nc=n/nl;
    creerMatrice(&matrice);
	for(p1=matrice.mat,q3=vec->vect;p1<matrice.mat+matrice.nl;p1++){	
        for(q1=*p1;q1<*p1+matrice.nc;q1++,q3++){
            *q1=*q3;
        }
    }
    return matrice;
}
//______________________________________Question :7___________________________________________
//Calculer Le Trace d'une Matrice
double getTrace(const matrice_t *prtmatr)
{
    double somme=0;
    vecteur_t v=getDiag(prtmatr);
    int i=0;
    double *p;
    for(p=v.vect;p<v.vect+v.n;p++)
    {
        somme+=*p;
    }
   return somme;
}
//______________________________________Question :8___________________________________________
//Extraire la sous matrice d une Matrice en eliminant la ligne i et la colonne j

matrice_t extracSubMatrice(const matrice_t *petmatr,int i,int j)
{
    matrice_t mat;
    double **p1,**p3,*q1,*q2,*q3;
    mat.nl=petmatr->nl-1;
    mat.nc=petmatr->nc-1;
    creerMatrice(&mat);
    for(p1=petmatr->mat,p3=mat.mat;p1<petmatr->mat+petmatr->nl;p1++){	
        for(q1=*p1,q3=*p3;q1<*p1+petmatr->nc;q1++){
			if(p1-petmatr->mat!=i && q1-*p1!=j){
				*q3 = *q1;
				q3++;
			}
        }
        if(q3 != *p3){
        	p3++;
        }
    }
    return mat;
}
//______________________________________Question :9___________________________________________
//Determier la ligne qui contient le maximum de zéros

int getBestligneCol(const matrice_t *prt)
{
    double **p1,*q1;
    int *com;
    com=(int *)malloc(prt->nl*sizeof(int));
    int *p;
    int InLigneBest;
		for(p1=prt->mat,p=com;p1<prt->mat+prt->nl;p1++,p++){
            int somme=0;
			for(q1=*p1;q1<*p1+prt->nc;q1++){
				if(*q1==0)
                {
                    somme++;
                }
			}
            *p=somme;
		}
    int max=0;
    int i;
    for(i=0,p=com;p<com+prt->nl;p++,i++)
     {
         if (max<*p)
         {
             max=*p;
             InLigneBest=i;
         }
     }
     return InLigneBest;
}
//______________________________________Question :10___________________________________________
//Calculer Le Determinant d'une Matrice
double getDet(const matrice_t *ptr1){
	assert(ptr1->nc == ptr1->nl);//il faut que une Matrice carrée
    double **p1,det;
    if(ptr1->nl == 2){
    	return (ptr1->mat[0][0]*ptr1->mat[1][1])-(ptr1->mat[0][1]*ptr1->mat[1][0]);
	}
    else{
        matrice_t m1;	
	    for(p1=ptr1->mat;p1<ptr1->mat+ptr1->nl;p1++){	
		m1=extracSubMatrice(ptr1,p1-ptr1->mat,0);
		det += pow(-1,p1-ptr1->mat)*(**p1)*getDet(&m1);
         }
    }
    return det;	
}
//______________________________________Question :11___________________________________________
//Determier le Transpose d'une Matrice
matrice_t getTranspose(const matrice_t *ptr1){
    double **p1,*q1,temp;
    matrice_t trans;
    trans.nl=ptr1->nc;
    trans.nc=ptr1->nl;
    creerMatrice(&trans);
    for(p1=ptr1->mat;p1<ptr1->mat+ptr1->nl;p1++){	
        for(q1=*p1;q1<*p1+ptr1->nc;q1++){
        	trans.mat[q1-*p1][p1-ptr1->mat] = *q1;
        }
    }
    return trans;
}
//______________________________________Question :12___________________________________________
////Calculer Le Produit sacalaire entre une scalaire et une Matrice qu'il est une Matrice
matrice_t produitScalaire(const matrice_t *ptr, double Scalaire)
{
	matrice_t res;
	res.nl=ptr->nl;
	res.nc=ptr->nc;
    double **p1,*q1,**p2,*q2;
	creerMatrice(&res);
    for(p1=ptr->mat,p2=res.mat;p1<ptr->mat+ptr->nl;p1++,p2++){	
        for(q2=*p2,q1=*p1;q1<*p1+ptr->nc;q1++,q2++){
             *q2=*q1*Scalaire;
        }    
        }
    return res;
}
//Determier la Comatrice d'une Matrice

matrice_t getCom(const matrice_t *ptr1)
 {
    double **p1,*q1,**p3,*q3;
    matrice_t mat,m1;
    mat.nl=ptr1->nl;
    mat.nc=ptr1->nc;
    creerMatrice(&mat);
    for(p1=ptr1->mat,p3=mat.mat;p1<ptr1->mat+ptr1->nl;p1++,p3++){	
        for(q1=*p1,q3=*p3;q1<*p1+ptr1->nc;q1++,q3++){
			m1=extracSubMatrice(ptr1,p1-ptr1->mat,q1-*p1);
			if(m1.nl==1 && m1.nc==1){
				*q3=pow(-1,p1-ptr1->mat+1+q1-*p1+1)*(**m1.mat);
			}
			else{			
				*q3=pow(-1,p1-ptr1->mat+1+q1-*p1+1)*getDet(&m1);
			}
        }
    }
    return mat;
 }
//Determier la Inverse d'une Matrice

matrice_t getInverse(const matrice_t *ptr1)
{
    
    matrice_t com,matinv;
    matrice_t m1,trans;
    double **p1,**p2,**p3,*q1,*q2,*q3,invdet;
    com=getCom(ptr1);
    invdet = 1/getDet(ptr1);
    assert(ptr1->nc == ptr1->nl && invdet!=0);//il faut que une Matrice carrée et son Determinant different a zéro
    printf("det : %f\n",invdet);
    trans = getTranspose(&com);
	matinv.nl=ptr1->nl;
    matinv.nc=ptr1->nc;
    matinv=produitScalaire(&trans,invdet);
    return matinv;
}
//______________________________________Question :13___________________________________________
//Determier la Solution d'une  Systeme Lineaire A.X=Y
vecteur_t SolveSys(const matrice_t *A,const vecteur_t *Y)
{
    matrice_t Inverce ;
    Inverce=getInverse(A);
    vecteur_t X;
    X=MatDotVect(&Inverce,Y);
    return X;
}


	

