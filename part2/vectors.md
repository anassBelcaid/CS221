---
layout : page
title  : STL vectors
date   :  2021/03/28  
permalink : /vectors/
---

1. [Les Collections de C++](#collections)   
    - [Collections STL](#stlcollections)
    - [Class Vector](#vector)
    - [Inialisation](#initialisation)
    - [Itération](#iteration)
    - [Methodes](#methods)
    - [Vecteurs multi-dimentionels](#multivect)

2. [Conteneurs Stanford](#stanford)

    - [Vecteur Stanford](#stanfVect)
    - [Grille](#grid)
    - [démonstration](#demo)

3. [Applications](#applications)
    - [Manipulation d'image](#imagemanip)
    - [jeu de vie](#gameLife)
    - [TicToc](#tictoc)
    
## [Les Collections de C++](#collections)
<a name='collections'></a>

L'un des aspets les plus puissants de **c++** réside dans ces `collections` dans
la bibliothèque standard **STL**.

Une `colleciton` is emplacement qui stocke un ensemble d'objets. Ils sont
implémentés comme des `template` ce qui les rends extrément fléxibles pour les
éléments supportés.

### [Liste des collections](#stlcollections)
<a name='stlcollections'></a>

Une `collection` gère l'espace mémoire de ces éléments et vous offre un ensemble
de méthodes pour les gérer ( en préférence par des itérateurs).

Nous allons commencer par les **six** collections importantes qui sont présentés
dans la figure suivante:

<div class="figcenter fighighlight">
<img src="{{ site.url }}{{ site.baseurl }}/assets/vectors/collections.png"
  width="400">
<div class="figcaption">
Ensemble de collections basiques de la bibliothèque STL.
</div>
</div>



### [Les Vecteurs.](#vector)
<a name='vector'></a>


La collection `vector` dans **C++** est un tableau **dynamique** qui est capable
de se redimensionner automatiquement. Le redimensionnement est réalisé
automatiquement pour vous si les éléments sont **ajoutés** ou **supprimés**. Les
éléments sont stockés dans un espace **contigu** pour vous offir la possibilité
de les traiter comme des vecteurs normaux et d'utiliser les `iterators`.

Il est recommandé d'utiliser cette collection s:

- On traite un tableau dont la taille change **régulièrement**.
- La taille du tableau n'est pas connu **à priori**.
- Cette collection ne vas pas **vous forcer à préciser la taille maximale** à
l'initialisation.


Pour utiliser cette collection, on doit importer la bibliothèque `<vector>`.

### [Initialisation](#initialisation)
<a  name="initialisation"></a>

Cette classe possède plusieurs **constructeurs** dont les plus utilisés sont
résumés dans le **listing** suivant:

1. Constructeur vide $$\mathcal{O}(1)$$.

```cpp
//Créer un vecteur vide des entiers
vector<int> v;  //capcity =  0

//Vecteur des chaines
vector<string> strings;
```


2. Constructeur avec une taille $$\mathcal{O}(n)$$

```cpp
//Créer un vecteur vide des entiers
vector<int> V(n);        //vecteur avec n éléments.
```

3. Constructeur avec valeur initiale.

```cpp
//Créer un vecteur vide des entiers
vector<int> V(n, value);        //vecteur avec n éléments inialisés à value
```


4. Constructeur avec des itérateurs. $$\mathcal{O}(n)$$.

Permet d'initialiser en donnant des **adresses mémoires**.

```cpp
int V[5]{4, -1, 3, 2, 11};  //Tableau statiques

//initialiser un vecteur avec les adresses de V
vector<int> T(V, V+4);     //Taille 4

//Initialiser un autre vecteur de T
vector<int> T2(T.begin(), T.begin()+2);
```






### [Itération](#iteration)
<a href='iteration'></a>

On peut itérer un `vector` en utilisant les boucles d'indices ou la boucle
`foreach` déja établie dans les vecteurs simples.


```cpp
vector<float> T(5);

//Boucle indices
for(int i=0; i< T.size(); i++)
    cout<<T[i]<<" ";

//Boucle for each
for(auto v: T)
    cout<<v<<" ";
```

### [Methodes Vector](#methods)
<a name='methods'></a>

Une fois déclarée, la collection offre l'accès a données de bases comme:

1. `T[i]`: Référence sur le ième élément 
2. `T.at(i)`: Référence sur le ième élément avec vérification de limites 
3. `T.size()`: Longueur des éléments 
4. `T.capacity()`: Capacité du vecteur 
5. `T.empty()`: Indique si le vecteur est vide. 
6. `T.front()`: Référence sur le **premier** élément. 
7. `T.back()`: Référence sur le **dernier** élément 
8. `T.begin()`: itérateur qui pointe au **début**.
9. `T.end()`: Itérateur qui pointe à la **fin**.



Pour modifier le tableau on possède la liste des fonctions suivantes:


1. `push_back(value)`: Ajoute une valeur à la fin. (En **moyenne**
   $$\mathcal{O}(1)$$.)

2. `insert(iterator, value)`: Insérer à la position **iterator**
   $$\mathcal{O}(n)$$.
3. `pop_back()`: détruit le **dérnier élément** $$\mathcal{O}(1)$$.
4. `erase(iterator)`: détruit l'élément à l'adresse **iterator**.
   $$\mathcal{O}(n)$$.
5. `erase(begin, end)`: détruit les élément de **begin** à **end**.



### [Vecteurs multidimentionels](#multivect)
<a name='multivect'></a>

Une matrice ou tableau **multidimentionnel** est un vecteur dont chaque élément
est un **vecteur** (unidimentionnel).

Dans **C++**, on  peut déclarer cette matrice soit en utilisant des vecteurs
simples:


```cpp
//Matrice trois-trois
float A[3][3];        

//Déclaration puis initialisation
int B[3][2]={ {1,2},{2,3}, {4,5} };

//Accéder aux éléments
for(int i=0; i<3; i++)
    for(int j=0; j<2; j++)
      //Utiliser B[i][j]
```


On peut utiliser la classe `vector` pour stocker des matrices.

```cpp
//matrix using 4 rows and 3 columns
vector< vector<float> > matrix(4, vector<float>(3));

//Matrix with 5 rows and 2 columns with initial value 12
vector< vector<float> > matrix(5, vector<float>(2, 12));
```


On peut parcourir la matrice en utilisant le même **mécanisme** d'indices.

```cpp
//loop over the rows
for(int i=0; i<4; i++)
    //Loop over the columns
    for(int j=0; j<3; j++)

        //Use indexing matrix[i][j]
```


On peut aussi utiliser la paradigme de la boucle `for each` étant donné qu'on
manipule des **stl vector**.


```cpp

//using a for each over the line
for(auto line: matrix)
    for(auto value: line)
        //use of value
```


### Exercice : Produit matrice / vecteur

On cherche à écrire un programme qui implémente la **multiplication** entre une
matrice $$A\in\mathcal{M}_{n,m}$$  et un vecteur $$x\in\mathbb{R}^m$$:


$$
B = \begin{pmatrix} a_{1,1} & a_{1,2}&\ldots& a_{1,m}\\
                a_{2,1} &  a_{2,2}&\ldots&a_{2,m}\\
                \vdots & \vdots & \vdots &\vdots \\
                a_{n,1} & a_{n,2}&\ldots & a_{n,m}\end{pmatrix}

\begin{pmatrix}x_1\\x_2\\\vdots\\x_m\end{pmatrix}
$$


On rappelle que chaque composentes de $$B$$ est calculée selon la formule
suivante:

$$
B_i = \sum_{j=1}^m A_{i,j}x_j\quad 1\leq i \leq n
$$

## [Conteneurs Stanfords](#stanford)
<a name='stanford'></a>

### Vecteur Stanford]
<a name='stanfVect'></a>

### Grilles 
<a name='grid'></a>


### Démonstration
<a name='demo'></a>

