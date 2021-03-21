---
layout : page
title  : Vectors and Grids
date   :  2021/03/20  
permalink : /vectors/
---

<div class="figcenter">
<img 
    src="{{ site.url }}{{ site.baseurl }}/assets/vectors/banner.png"
    width="300"
    height="300">
</div>

    

Les **vecteurs** sont de simples structures de données pour stocker des données
de **même type**. Ils sont implémentés dans la plupart des langages de
programmation. Juste avec cette structure on peut résoudre une variété de
problèmes intéressants. Ils forment la base des collections, et tout programmer
sérieux doit être un `gourou` dans leurs manipulation.


## Table de matières

1. [Vecteurs statiques](#staticvect)
    - [Boite de DVD](#dvdbox)
    - [Définition d'un vecteur](#arraydef)
    - [Accès aux éléments](#indexing)
    - [Longueur et Capacité](#capacity)
    - [Passage fonctions](#arratoFun)
    - [Exercice d'application](#exo1)
    

2. [Les Collections de C++](#collections)   
    - [Collections STL](#stlcollections)
    - [Class Vector](#vector)
    - [Methodes](#methods)
    - [Vecteurs multi-dimentionels](#multivect)

3. [Conteneurs Stanford](#stanford)

    - [Vecteur Stanford](#stanfVect)
    - [Grille](#grid)
    - [démonstration](#demo)
    
    




## Vecteurs statiques
<a name='staticvect'></a>

Dans cette section, on introduit la notion simple de vecteur **statique** en
C++.

### Boite de DVD
<a name='dvdbox'></a>
On suppose qu'on dispose d'un ensemble de **DVD**s et qu'on veut les
**réaranger** (d'une manière compacte). 

> Quel sera le meilleur choix pour **stocker** ces DVD


- On peut trouver un grand casier pour mettre tous ces DVD?
- Le problème est qu'il est possible d'**ajouter** quelque uns, ou de vouloir se
**débarrasser** d'autres.
- Une autre considération, est que ce boitier doit contenir que des **DVD** et
non pas d'autre objets.
- Ainsi, ce boitier doit contenir des objets de **même type**. (i.e des objets
qui partagent les mêmes propriétés). Pour nous ces propriétés peuvent être:


1. Chaque DVD doit être dans son propre *couverture*.
2. Cette couverture porte le nom du **DVD**, le **cast** et d'autre détails.
3. Toutes les couvertures doivent avoir la **même taille**.


<div class="figcenter">
<img  src="{{ site.url }}{{ site.baseurl}}/assets/vectors/dvd_illustration.png"
   width="400">
</div>


Supposons qu'on doit construire une application qui gère tous nos **DVD** qui
sont dans notre inventaire. On doit choisir pour chaque **DVD** les propriétés
qui le représente. Aussi, on doit décider **le nombre maximal** de DVD qu'on
peut stocker dans notre inventaire.

> Ce nombre est très important car il va nous permettre de choisir la **taille**
de notre inventaire.


En programmation, une structure idéale pour stocker ces **DVD** est un vecteur
`array`.

### Définition Vecteur.
<a name='arraydef'></a>


> Un vecteur (array) est une collection d'objets. Ces objets peuvent être des
entiers, string, DVD, jeux ou livres, ect. Les objets sont stockés d'une
manitère **contigue** dans la mémoire. Ceci permet un accès **rapide** à chaque
composante de ce vecteur.


Comment peut on prendre cette définition et l'appliquer à des **DVDs**. Notre
sens inné de structure, nous pousse à réarranger notre collection ( l'un à coté
de l'autre). Nous les rangeons ainsi, pour nous faciliter la recherche de l'un
de ces DVD.


En **C++**, les tableaux possèdent une taille `N`. Cette valeur doit être
déclarée au **début**. Aussi on doit spécifier le **type** partagé par les
éléments de ce tableau.


```cpp
//Déclaration d'un tableau des entiers
int vec[15];     

//taille peut être une variable, mais un fois fixé
// Elle change pas
int N;
cout<<"Donner la taille: "
cin>>N

float vec2[N];
```


Voici un programme qui déclare la structure **DVD** et un vecteur pour stocker
une collection de ces DVD.



```cpp
#include <iostream>
#include <string>

using namespace std;

//Structure video
struct  DVD
{
    string name;
    string director;
    int year;
};

int main(int argc, char *argv[])
{
    //Store a line for a dvd
    string line; 

    //Getting the number of dvds
    int N;
    getline(cin, line);
    N = stoi(line);

    //Array of dvd
    DVD inventory[N];

    for(int i=0; i<N; i++)
    {
        getline(cin, line);
        inventory[i] = from_line(line);
    }

    for(auto dvd: inventory)
        cout<<dvd<<endl;

    return 0;
}
```

### Accès aux éléments
<a name='indexing'></a>


> Les deux opérations primitives pour un tableau sont l'écriture et la lecture dans ces composantes. Le reste des opérations est fondé sur ces opérations.


Pour ces deux opérations on utilise l'opérateur d'indexage `[i]` qui donne
une **référence** sur le *i*ème élément. Les éléments sont ordonnés de l'indice `0` à `N-1`.


```cpp
#Obtenir les données du premier DVD
auto dvd1 = inventory[0];

//Modifier les données de ce dvd
inventory[0].year = 2000;
```

Aussi pour parcourir ce tableau, on possède des trois boulces de base, traité dans le chapitre des string.


```cpp
for(int i=0 ; i<N; i++)
    //Utiliser inventory[i]

for(auto dvd: inventory)
    //utiliser dvd

for(auto &dvd: inventory)
    //utiliser dvd
```

### Capacité et longueur
<a name='capacity'></a>


Une question intéressante qui se pose est:

> Si une personne vous demande quelle la taille de votre collection, quel sera
votre réponse.

Il y as deux réponses possibles pour cette question:


1. Le nombre d'éléments **maximal** que la collection peut contenir.
2. Le nombre d'élément **actuel** qui sont dans la collection.


Les deux réponses sont **correctes** et possède une signification différente
qu'on doit maitriser. La première est appellée `capacité` du tableau, alors
que la deuxième est la `longueur` `.


```cpp
//Tableaud de capacité 100
int tab[100];

//insérer quelque éléments
tab[0] = 3;  //[lenght=1, capacity=100]
tab[1] = 4;  //[lenght=2, capacity=100]
tab[2] = 5;  //[lenght=3, capacity=100]
```


### Passage d'un tableau
<a name='arratoFun'> </a>


Un tableau (pure) en **C++** ne connait ni sa **capacité** ni sa **longueur**.
Ainsi une bonne pratique est de passer ces paramètres aussi à la fonction.


> Un tableau est une adresse, le seul mode de passage est celui par **adresse**!!!


```cpp
#include <iostream>

using namespace std;

void augment(int grades[], int capacity)
{
    //Essayer la boucle foreach pour une erreur classique
    for(int i=0; i<capacity; i++)
        grades[i]++;
}

int main(int argc, char *argv[])
{
    //Array with capacity 5
    int grades[5]{14, 16, 18, 10, 20};

    //Call with a function
    augment(grades, 5);
    
    //Printing
    for(auto v: grades)
        cout<<v<<" ";
    cout<<endl;
    return 0;
}
```


### Exercice d'application.
<a name='exo1'></a>

Pour un exercice d'application, on se propose d'écrire une `fonction` qui reçoit
un tableau et qui  rend le **nombre** des entiers contenant un nombre **pair** de
chiffres.


**Exemple 1**:

```
Input: nums = [12,345,2,6,7896]
Output: 2

Explications: 
12 contient 2 chiffres. 
345 contient 3 chiffres. 
2 contient 1 chiffres. 
6 contient 1 chiffres. 
7896 contient 4 chiffres. 
```


**Exemple 2**:
```
Input: nums = [555,901,482,1771]
Output: 1 

Explication: 
Seulement 1771 contient a nombre pair de chiffres.
```


## Les Collections de C++
<a name='collections'></a>


### Liste des collections
<a name='stlcollections'></a>

### Les Vecteurs.
<a name='vector'></a>

### Methodes Vector
<a name='methods'></a>


### Vecteurs multidimentionels
<a name='multivect'></a>


## Conteneurs Stanfords
<a name='stanford'></a>

### Vecteur Stanford]
<a name='stanfVect'></a>

### Grilles 
<a name='grid'></a>


### Démonstration
<a name='demo'></a>
