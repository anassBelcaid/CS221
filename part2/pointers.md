---
layout : page
title  : Memory and Pointers
date   :  2021/04/05
permalink: /pointers/
---


<div class="fighighlight figcenter">
<img src="{{ site.url }}{{ site.baseurl
}}/assets/pointers/illustration_xkcd.png"
width="500">
</div>

## Table de Matière

1. [Définition](#whatisapointer)
    - [Concept de mémoire](#memory)
    - [Pointeurs et Mémoire](#def)

2. [Syntaxe pointeurs](#syntax)
    - [Extraction](#deference)
    - [arithmétique](#arithmetique)
  
3. [Pointeurs et Tableaux](#arrays)
    - [Relation tableau et pointeur](#arraypointers)
    - [Parcours tableau](#looping)

4. [Pointeurs et fonctions](#functions)
5. [Gestion de Mémoire](#memoryall)
    - [Allocation](#new)
    - [Déstruction ](#delete)


## [Définition](#whatisapointer)
<a name='whatisapointer'></a>

- Une notion importante dans le langage **C++** est la notion de `pointeur`.
L'implémentation des **structures de données** utilise excessivement la notion
de **pointeurs**.
- Les pointeurs mettent le programmeur en contrôle du système de **mémoire**.
Ainsi, une maitrise de ce langage nécessite une familiarisation avec ce concept.


### [Concept de mémoire](#memory)
<a name='memory'></a>

La `mémoire` dans un ordinateur peut être conçue comme une grande rangée de
**boites**. Chaque **boite** possède une valeur et un indice associé.

> Ceci porte une grande analogie avec les tableau. (En effet une mémoire est un
tableau).


La mémoire d'un ordinateur (surtout la RAM(*Random Access Memory*)) un
gigantesque tableau. Les **boites** peuvent contenir différent **types**,
cependant les **indices** associée à chaque boite **ne change pas**.


{% graphviz %}
digraph {
    ranksep =0;
    node [shape=plaintext, fontcolor=red, fontsize=18];
    "Values:" -> "Index:" [color=white];

    node [shape=record, fontcolor=black, fontsize=14, width=4.75, fixedsize=true];
    values [label="<f0> A[0] | <f1> A[1] | <f2> A[2] | <f3> A[3] | <f4> A[4] | <f5> A[5]", color=blue, fillcolor=lightblue, style=filled];
    indices [label="0 | 1 | 2 | 3| 4 | 5",color="white"];

    { rank=same; "Values:"; values }
    { rank=same; "Index:"; indices }

    edge [color=blue];
}
{% endgraphviz %}

- En **C++**, l'emplacement de chaque boite est donnée par son adresse qui nous
donne son emplacement exacte dans la `RAM`.

Pour mieux comprendre la notion d'adresse, nous allons adopter la représentation
suivante pour une variable

<div class= "figcenter">
{% graphviz %}
graph{
     node [ fontname="Handlee", shape=record, fontsize=12];
     rankdir="LR";
     
     subgraph cluster_frontend {
         ranksep=0;
    label="Variable";
    value ;
    Address [fillcolor = forestGreen, style=filled, background="transparent"];
  }
         
}
{% endgraphviz %}
<div class="figcaption">
Représentation d'une variable avec son <b>nom</b>, la <b>valeur</b> qu'elle
contient et puis ce qui nous intéresse son <b> adresse</b>.
</div>
</div>


Par exemple le diagramme suivant


<div class= "figcenter">
{% graphviz %}
graph{
     node [ fontname="Handlee", shape=record, fontsize=12];
     rankdir="LR";
     
     subgraph cluster_frontend {
         ranksep=0;
    label="name";
    Erick;
    "200" [fillcolor = forestGreen, style=filled, background="transparent"];
  }
         
}
{% endgraphviz %}
</div>

représente une variable de type `string` nommée **name** qui contient la valeur
**Erick** et qui se trouve dans l'emplacement `200`.

> Un point à retenir est que c'est le **système d'exploitation** qui détermine
cette adresse et pas vous!!!

### [Pointeurs et Mémoire](#def)
<a name='def'></a>

Maintenant supposons qu'on veut créer une se **rappelle**(stock) ces adresses
pou nous!!!.

Supposons qu'on possède une variable **string** et qu'on peut connaitre son
**adresse**.


```cpp
//Variable simple
string var = "Erick"

//Variable (pointeur) qui contient l'adresse de var
int *pointer = &var;
```


<div class= "figcenter">
{% graphviz %}
digraph{
     node [ shape=record, fontsize=12];
     rankdir=LR;
     variable [

        label="var|Erick|<ad> 120";
     ];

     pointer [
     label="pointer|<pt> 120|132"
     ];

     pointer:pt -> variable:ad [label="Point to", color=orange,
     arrowhead=open, penwidth=2]

         
}
{% endgraphviz %}
<div class="figcaption">
Illustration du mécanisme d'un pointeur qui stocke l'adresse d'une autre
variable.
</div>
</div>


Ainsi on pourra définir un pointeur par:

> Un pointeur est tout simplement une variable qui peut stocker **des adresses**!!

L'adresse du pointeur lui même n'as pas d'importance, ainsi, on se limitera au
graphique suivant:

<div class= "figcenter">
{% graphviz %}
digraph{
     node [ shape=record, fontsize=12];
     rankdir=LR;
     variable [

        label="var|Erick|<ad> 120";
     ];

     pointer [
     label="<pt> pointer"
     ];

     pointer:pt -> variable:ad [label="Point to", color=orange
     arrowhead=open penwidth=2 ]

         
}
{% endgraphviz %}
</div>



Voici un simple programme illustrant l'aspect d'un **pointeur** qui peut
facilement **se déplacer** dans la mémoire du système.



```cpp
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
   //Déclarer deux variables simples
  int a = 13;
  int b = 15;

  //Déclarer une 
  cout<<"adresse de a: "<<&a<<endl;
  cout<<"adresse  de b: "<<&b<<endl;

  //Constuire un variable qui peut contenir une adresse
  int* p;
  
  //p  va recevoir la mémoire de a
  p = &a;
  cout<<"P pointe sur : "<<p<<endl;

  //Maintenant p va changer de place
  p = &b;
  cout<<"Maintenant P pointe sur : "<<p<<endl;

  return 0;
}
```


<div class= "figleft">
{% graphviz %}
digraph{
     node [ shape=record, fontsize=12];
     rankdir=LR;
     a [

        label="a|13|<ada> 110";
     ];

     b [

        label="b|15|<adb> 150";
     ];
     pointer [
     label="<pt> pointer"
     ];

     pointer:pt -> a:ada [label="Point to", color=orange
     arrowhead=open penwidth=2 ]

         
}
{% endgraphviz %}
</div>


<div class= "figcenter">
{% graphviz %}
digraph{
     node [ shape=record, fontsize=12];
     rankdir=LR;
     a [

        label="a|13|<ada> 110";
     ];

     b [

        label="b|15|<adb> 150";
     ];
     pointer [
     label="<pt> pointer"
     ];

     pointer:pt -> b:adb [label="Point to", color=orange
     arrowhead=open penwidth=2 ]

         
}
{% endgraphviz %}
</div>

**Points à retenir**

- Chaque espace dans la mémoire (ainsi chaque variable) possède une `adresse`.
- Inversement, chaque adresse correspond à un emplacement **unique** dans la
mémoire.
- L'ordinateur connait l'adresse de chaque variable dans votre programme.
- Etant donné un adresse mémoire, l'ordinateur peut **extraire**  la valeur
stockée dans cet emplacement.
- Même si les adresses sont aussi des **nombres**, `C++` les traitent
différemment pour éviter des erreurs d'exécution.


## [Syntaxe pointeurs](#syntax)
<a name='syntax'> </a>

pour déclarer un pointeur, on doit **précéder** le type par une étoile.


```cpp
//Pointeur sur un entier
int* p;

//pointeur sur un string
string* p2;

//Pointeur sur un vecteur<entier>
vector<int> * pV;
```


### [Extraction](#deference)
<a name='deference'></a>

Une fois déclaré, un pointeur peut facilement `extraire` la valeur stockée dans
cette adresse mémoire. Ceci est réalisé par l'opérateur d'extraction `*`.

> A noter une grande ambigüité, entre l'étoile de déclaration et celle de
l'extraction.


```cpp
//Decraling a simple pointer
int a = 14;
int* p = &a;

//Afficher [(adress|value)] par deux mécanismes
cout<<"[value: "<<a<<", adress: "<<&a<<"]"<<endl;
cout<<"[value: "<<*p<<", adress: "<<p<<"]"<<endl;
```


On note aussi, que si un pointeur ne possède pas une adresse (pas de valeur), il
doit être initialisé à la `nullptr`. 

```cpp
int *p = nullptr;
```

> Dans ce cas, il faut faire attention et ne pas utiliser l'opérateur
d'extraction, sinon on fera face à l'erreur classique de **segmentation fault**.


Aussi on peut tester si un pointeur est `null` dans l'instruction de branchement
`if`.

```cpp
if(ptr)   //Passe le test si ptr est null
if(!ptr)  // Réussit si le pointeur n'est pas null
```
### [arithmétique](#arithmetique)
<a name='arithmetique'></a>

Il existe plusieurs opérations **arithmétique** disponibles dans pour les
pointeurs, on note les plus importants. 

Pour deux pointeurs, $$p_1$$ et $$p_2$$:

- `p++`: Passer à l'adresse **suivante** (sauter par une case).
- `p + d`: Sauter par $$d$$ cases.
- `p--`: Passer à l'adresse **précédente**. 
- `p-d`: Sauter par $$d$$ à gauche.
- `p1 < p2`: booléen qui indique si l'adresse de $$p_1$$ **précède** celle de
$$p_2$$.





## [Pointeurs et Tableaux](#arrays)
<a name='arrays'></a>

### [Relation tableau et pointeur](#arraypointers)
<a name='arraypointers'></a>

Un tableau statique dans **C++** n'est qu'un pointeur mais qui est `constant`.
C'est à dire, on ne peut pas changer son adresse pour ne pas **perdre** l'espace
mémoire référencé.


Ainsi supposons qu'on a déclaré un tableau statique:


```cpp
//Déclarer un tableau statique
int A[]{2,4,5,9,1};
```

- Première remarque est qu'on peut pas modifier $$A$$ par les opérateurs
arithmétiques. Par exemple une instruction comme `A++` va lancer une **erreur**.

- On peut manipuler le vecteur $$A$$ soit par des indices soit pas des pointeurs
comme le montre la figure suivante:


<div class="figcenter">
{% graphviz %}
digraph {
    node [shape=plaintext, fontcolor=red, fontsize=18];
    "Pointers:" -> "Values:" -> "Indices:" [color=white];

    node [shape=record, fontcolor=black, fontsize=14, width=4.75, fixedsize=true];
    pointers [label="<f0> A | <f1> A+1 | <f2> A+2 | <f3> A+3 | <f4> A+4 | <f5> A+5", color=white];
    values [label="<f0> A[0] | <f1> A[1] | <f2> A[2] | <f3> A[3] | <f4> A[4] | <f5> A[5]", color=blue, fillcolor=lightblue, style=filled];
    indices [label="0 | 1 | 2 | 3| 4 | 5", color=white];

    { rank=same; "Pointers:"; pointers }
    { rank=same; "Values:"; values }
    { rank=same; "Indices:"; indices }

    edge [color=orange];
    pointers:f0 -> values:f0;
    pointers:f1 -> values:f1;
    pointers:f2 -> values:f2;
    pointers:f3 -> values:f3;
    pointers:f4 -> values:f4;
    pointers:f5 -> values:f5;
}

{% endgraphviz %}

<div class="figcaption">
Relation entre Tableau statique et pointeurs.
</div>
</div>


### [Parcours tableau](#looping)
<a name='looping'></a>

Pour parcourir le tableau, on pourra utiliser l'une de ces trois méthodes:
```cpp
//Parcours du tableau par indices
for(int i=0; i<5; i++)
    cout<<A[i]<<" ";

//Même boucle en utilisant A
for(int i=0; i<5; i++)
    cout<<*(A+i)<<" ";

//Boucle préférée (prendre un autre pointeur)
for(int* p=A; p<A+5; p++)
    cout<<*p<<" ";
```



#### Exercice:

On suppose qu'on possède d'un vecteur **stl**. On vous demande d'écrire une
fonction pour afficher ce vecteur.

> Vous ne devez pas utiliser l'opérateur [i] ni la fonction at.


```cpp

void printVector(vector<int> Arr)
{
    //Votre code (interdit d'utiliser Arr[i] ou Arr.at(i) )
}
```


## [Pointeurs et fonctions](#functions)
<a name='functions'></a>

Dans le cours des fonctions, on as évoqué le deux types de passages qui sont
soient

- par copie.
- par référence.
- par `adresse`.


Il est temps de couvrir le troisième de passage qui est un passage par `adresse`
qui utilise la notion de pointeurs.

Pour illustrer ce type de passage, nous allons nous référer à un exemple
classique qui est celui de **permutation** de deux nombres. Celle ci offre
l'opération  de base de **tris**.


Le programme suivant implémente les trois versions de se passage pour cette
fonction:


> Concentrez vous sur la dernière fonction qui implémente un passage par adresse
 en utilisant des pointeurs. 


> Remarquer aussi l'utilisation de l'opérateur d'extraction pour accéder aux
valeurs.


```cpp
#include <iostream>

using namespace std;

//First function no hope
void swap_copy(int a, int b)
{
    auto tmp = a;
    a        = b;
    b        = tmp;
}

//Second version (Prefered) references
void swap_ref(int &a, int &b)
{
    auto tmp = a;
    a        = b;
    b        = tmp;
}


//Third version (advanced) adresse
void swap_add(int *a, int *b)
{
    auto tmp = *a;
    *a       = *b;
    *b       = tmp;
}


int main()
{
  int a = 45;
  int b = 30;
 
  //Calling the first one
  swap_copy(a, b);
  cout<<"State after swap copy: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";

  //Calling the second one
  swap_ref(a, b);
  cout<<"State after swap_ref: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";


  a = 45;
  b = 30;

  //Call by adress (pay attention to the adresses)
  swap_add(&a, &b);
  cout<<"State after swap_add: \n";
  cout<<"[a: "<<a<<", b:"<<b<<"]\n";


  return 0;
}
```



## [Gestion de Mémoire](#memory)
<a name='memoryall'></a>

Nous allons maintenant tourner note attention à l'avantage principal
d'utilisation des pointeurs qui est celui la `gestion de la mémoire`. Ce
principe nous permet de **créer** ou de **supprimer** des emplacements mémoire
en temps d'exécution!!


Ceci nous permet de créer des structures **dynamiques** qui peuvent changer de
taille comme un tableau.

Dans des langages de haut niveau comme `Java` ou `Python` le compilateur se
préoccupe de la gestion de la mémoire pour vous. Cependant dans un langage
avancé comme `C++` c'est au programmeur gérer sa propre mémoire.


Pour gérer la mémoire, on doit maitriser deux opération de bases qui sont:

- Allocation (Création).
- Déallocation (Destruction).


### [Allocation](#new)
<a name='new'></a>


Pour  Créer un espace mémoire, on utilise ( comme en **Java**) le mot clé
`new`. Par exemple:


```cpp
//pointeur
int *ptr;

//Allocation d'une seule variable
ptr = new int;

//Donner une valeur à ptr
*ptr = 45;
```

Dans cet exemple, nous avons  **réservé** une seule case mémoire. L'adresse de
cette case est conservée dans le pointeur `ptr`.


> Une question qui se pose, est comment réserver plusieurs case, qui est le cas
d'un tableau.


```cpp
//pointeur qui va servir comme tableau
int *Arr;

//Reserver N cases
Arr = new int[3];

// Réserver une autre taille (n'est pas recommendé car il faut supprimer)
Arr = new int[6];
```


D'une manière générale pour réserver $$N$$ cases d'un type `T` est:

```cpp
T* ptr = new T[N]; 
```


### [Déstruction ](#delete)
<a name='delete'></a>

Comme mentionné, en **C++**, le programmeur qui doit gérer se propre mémoire
Ainsi

> Si vous réserver un espace mémoire par new, C'est **votre responsabilité** de
le détruire!!!.

La destruction des objets est réalisée par l'opérateur `delete`.

- `delete ptr`: Pour un pointeur qui stocke une seule variable.
- `delete [] ptr`: Pour un pointeur qui stocke un tableau.


```cpp
//Pointeur
int *ptr;

//Réservation d'une seule case
ptr = new int;

//Détruire cette case
delete ptr;

//Réservation tableau
ptr = new int[5];

//Déstruction tableau (remarquer le [])
delete [] ptr;
```


