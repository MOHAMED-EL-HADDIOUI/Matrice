#ifndef _MATRICES
  #define _MATRICES
  #define NMAX 100
  typedef struct matrice_t matrice_t;
  struct matrice_t{
    int nl,nc;
    //double **mat; if faut allouer nl*mc cases de type double 
    double **mat;//allouer nl poiteurs puis pour chaque poiteur allouer nc double
  };
  typedef struct vecteur_t vecteur_t;
  struct vecteur_t{
    int n;
    double  *vect;
      //double *vect; if faut allouer n cases de type double 
  };

  void creerMatrice(matrice_t *);
  void scanMatrice(matrice_t *);
  void printMatrice(const matrice_t *);//pour eviter une copie (lourde)
  matrice_t add(const matrice_t *,const matrice_t *);
  //Question 1
  matrice_t produit(const matrice_t *,const matrice_t *);
  //Question 2
  void CreerVecteur(vecteur_t *);
  void scanVecteur(vecteur_t *);
  void printVecteur(const vecteur_t *);
  vecteur_t MatDotVect(const matrice_t *,const vecteur_t *);
  //Question 3
  vecteur_t getDiag(const matrice_t *);
  //Question 4
  vecteur_t get2emeDiag(const matrice_t *);
  //Question 5
  vecteur_t Mat2Vect(const matrice_t *);
  //Question 6
  matrice_t Vect2Mat(const vecteur_t *,int);
  //Question 7
  double getTrace(const matrice_t *);
  //Question 8
  matrice_t extracSubMatrice(const matrice_t *,int,int);
  //Question 9
  int getBestligneCol(const matrice_t *);
  //Question 10
  double getDet(const matrice_t *);
  //Question 11
  matrice_t getTranspose(const matrice_t *);
  //Question 12
  matrice_t getCom(const matrice_t *);
  matrice_t produitScalaire(const matrice_t *, double);
  matrice_t getInverse(const matrice_t *);
  //Question 13
  vecteur_t SolveSys(const matrice_t *,const vecteur_t *);
#endif