---
layout : page
title  :  Fonctions
date   :  2021/03/17  
permalink: /basics/
categories:  jekyll updates
---

# Table de matière

1. [Fonctions](#functions).
2. [Structures](#structures)
3. [Includes](#includes).



# Rappel des bases
<a name='linkLabel'></a>

L'objectif de cette section est rappeler (aussi introduire) les notions de
codage de base en **C++**.

## fonctions
<a name='functions'></a>
Que vous utiliser le paradigme **procédural** ou **Orienté objet**, vous aurez
besoin de développer des `fonctions`.

> Une fonction est un groupe d'instructions pour compléter une tâche.

> 1. La tâche d'une fonction doit être simple pour simplifier la
     **réutilisation**.

> 2. Le code d'une fonction ne doit pas généralement dépasser 10 lignes.



Pour illustrer l'utilisation des fonctions, nous proposons de résoudre le
problème de **décomposition en facteurs premiers**

$$
 n = \prod_{i} p_i ^{r_i}
$$

où $$p_i$$ sont des nombres premiers et $$r_i$$ forment leur degrés.


Une **modélisation** simple de ce problème consiste à implémenter les fonctions
suivantes:

- `bool is_prime (int n)`: pour vérifier si un nombre est premier.

```cpp

bool is_prime(int n)
{
    auto limit = floor( sqrt(n) ) ;
    for(auto div = 2; div<= limit; div++)
        if( n % div == 0)
            return false;

    return true;
}
```


- `int order( int n, int facteur)`: pour calculer l'ordre d'un facteur.

```cpp
int order(int n, int factor)
{
    auto count = 0;

    while( n % factor == 0)
    {
        count ++;

        n /= factor;
    }

    return count;
}
```

- `void print_decomposition(int n)`: Fonction pour afficher la décomposition.

```cpp
void decomposition(int n)
{
    //premier affichage
    cout<<n<<"= ";
    
    //Facteur à tester
    auto fact = 2;

    //Tant que n contient des facteurs
    while( n >1)
    {
        if( (n % fact == 0) && (is_prime(fact)) ) 
            {
                auto r = order(n,  fact);

                cout<<"("<<fact<<"**"<<r<<") ";

                n /= pow(fact, r);
            }

        fact++;
    }

    cout<<endl;
}
```


Comme en `Java`, on peut **surcharger** en modifiant soit:

1. Le nombre d'arguments.
2. Soit le type de paramètre.


A titre d'exemple supposons qu'on offre l'ensemble des fonctions suivantes:

```cpp
//F1
float Log();

//F2
int Log(int l);

// F3
float Log(float l);

// F4
float Log(float l, float base);
```

Ces fonctions peuvent être facilement **différentiable** par leurs paramètres.


```cpp
auto v1 = Log(5.5);      //F3

auto v2 = Log(5)         // F2

auto v3 = Log(3, 3);    //F4

auto v4 = Log()        //F1
```

Par contre les deux fonctions suivantes ne peuvent pas **coexister**.


```cpp
int Log(int a)

float Log(float b)  //Problème
```

Vu que la seule différence entre eux est la **valeur de retour**.


<div class="fig figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/overloading_by_type.png" >
</div>
<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/overloading_by_number.png" width="300">
</div>
  <div class="figcaption"> Surchage des fonctions en C++. Surcharge peut être
  effecturé en variant le type d'argument soit en variant le nombre d'arguments.</div>
</div>



> A la différence entre **Java**, en C++ on peut spécifier des valeurs par
**défaut** a nos arguments.

Considérons alors la déclaration suivante:


```cpp
void temp(int i=10, float f = 8.8)
```

C'est une fonction qui  prend deux arguments qui possèdent une valeur initiale.
Ainsi dans l'appel si on fournit pas une valeur, elle peut être remplacée par sa
valeur par **défaut**. Cependant il faut faire attention à l'ordre comme
illustrée dans la figure suivante:



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/default_arguments.png" >
  <div class="figcaption"> Illustration des appels des fonctions à valeurs par
  défaut. On remarque qu'on peut appeler la fonction soit par un seul, deux ou
  même sans argument. Cependant il faut faire attention à l'ordre. Exemple
  illustré dans le quatrième cas</div>
</div>



### Passage d'arguments

En **C++**, il existe trois mode de passage d'arguments:


1. Par copie (défaut)
2. Par référence.
3. Par adresse


Pour illustrer la différence entre ces modes, considérons l'exemple d'une
fonction double la valeur de son argument.


```cpp
#include <iostream>

using namespace std;

//Function to double the value of its argument
int doubleValue(int x)
{
    x *= 2;

    return x;
}

int main(int argc, char *argv[])
{
    int myValue = 5;
    int result = doubleValue(myValue);

    cout << myValue << endl; // myValue will not change
    cout << result << endl;
    return 0;
}

```


Comparons maintenant l'exécution avec un passage par **référence**.


```cpp
//Function to double the value of its argument
int doubleValue(int & x)
{
    x *= 2;
}
```
- Avec ce type de passage, on as pas besoin de **renvoyer** la valeur doublée.
- Avec des références, **C++** pour permet de modifier vos arugments sans copier
les données. 
- Avec ce type de passage, il faut faire **attention**.
- Ce type de passage est souvent recomandé pour passer des arguments lourds en
mémoire comme les **vecteurs**.

- Dérnier point, pour les fonctions de passage par référence, il faut passer une
**variable**. A titre d'exemple, l'appel suivant donnera une erreur

```cpp
doubleValue(15) // Expect an l-value???
```

> On présentera le troisième mode de passage d'arguments une fois on introduit
les **pointeurs**


## Structures
<a name='structures'></a> 

> Une **structure** en C++ est un groupement de données **nommées** pour
 représenter un nouveau type.


Prenons par exemple, l'instance `Etudiant` dans une base de données. Elle sera
représenté par

1. name (`string`)
2. state (`string`)
3. age   (`int`)

On pourra déclarer cette structure en **C++** par le mot clé `struct`.

```cpp
struct Student {
   string name;        //Attribut ou Field
   string state; 
   int age;
};

//Utilisation
Student S;
S.name = "Karim";   //. pour accéder aux champs
S.state = "Fes";
S.sage = 19;
```

L'utilisation des structures nous permet de **regrouper** des informations. Par
exemple pour afficher les informations d'un étudiant on passe une seule
référence `Student` au lieu de passer chaque champs.


```cpp

void printStudentInfo(Student S)
{
   cout<<S.name<<" From "<< S.state<<" ( "<<S.age<<" )"<<endl; 
}
```

On peut aussi initialiser les champs d'une structure par 
l'opérateur `{}`

```cpp
Student S = {"Imad", "Fes", 19};  //Il faut attention à l'ordre
```

### Structure Pair


- Une `pair` est une structure avec deux attributs.
    - first
    - second
- Cette structure est un `template` (generic in Java), ce qui vous permet de
controller le type de ces champs.
- Pour utiliser `pair` il faut inclure son entête `include<utility>`



```cpp

//Déclaration d'une simple pair d'entiers
pair<int, int> point;

//Accéder aux champs
point.first = 3;
point.second = 4;
```


On peut utiliser l'intialisation **uniforme** pour donner des valeurs directes
aux champs.


```cpp
//Déclaration d'une simple pair d'entiers
pair<int, int> point{4,5}

//Afficher les valeurs
cout<<point.first<<", "<<point.second<<endl;
```


Aussi on peut combiner `auto` et l'opérateur  `[]` pour extraire facilement le
contenu des deux variables.

```cpp
//Déclaration d'une simple pair d'entiers
pair<int, int> point{4,5}

//Extraction des valeurs
auto [x, y] = point;

//Afficher les valeurs
cout<<x<<", "<<y<<endl;
```


Une méthode très utile est la fonction `make_pair` qui est une fonction
**générique** qui permet de créer une pair sans la spécéfication des types.


```cpp
//Déclaration d'une simple pair d'entiers
auto point = make_pair(22, 33);

//Extraction des valeurs
auto [x, y] = point;

//Afficher les valeurs
cout<<x<<", "<<y<<endl;
```

- Pour un ensemble de méthodes disponible pour la structure **pair**. Voir la
page officielle <a href=" http://www.cplusplus.com/reference/utility/pair/">documentation pair </a>
- Si on veut stocker plusieurs valeurs en même temps, **C++**, offre aussi la
structure <a href="https://en.cppreference.com/w/cpp/utility/tuple">Tuple</a>
- Les **pair** sont souvent utilisés pour écrire des fonctions qui renvoient
plusieurs valeurs. Pour illustrer ce principe, développons la fonction classique
pour la résolution d'une équation de second ordre dans $$\mathbb{R}$$.


$$
ax^2 +bx + c = 0
$$

Ainsi, votre tache est de développer une fonction

```cpp
pair<bool, pair<double, double> > quadratic(int a, int b, int c)
```

Cette fonction renvoie une **pair** qui indique si une solution existe ou non.
Si oui la deuxième valeur contient les deux solutions.


> Solution dans la démo.



## Includes
<a name='includes'></a>

<div class="fig figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/header_icon.png"
  width="100" height="100" >
</div>

- Comme C++ est base sur **C**, il utilse des `entêtes` (*header*). Un fichier
entête maintient générélement des **définitions* de fonctions, classes et
structures.

- Les fichiers **entêtes** peuvent faciliter aussi l'étape de compilation de
large projets.

-  Les fichiers entêtes portent l'extention **.h** (ou **\*.hpp**).
- Un point important est que ces fichiers sont généralement inclus en
hiérarchie. Un fichier **.h** qui inclue un autre. Aussi fichier **.cpp** peut
inclure les deux fichiers en même temps. Pour éviter que les fonctions définies
deux fois, on utilise:

    - `#pragma once`
    - Ceci implique que ce fichiers sera inclut une seule fois.
    - Voici un exemple simple utilisant un *header*.


```cpp
// include_example.h
#pragma once
int square(int x);
bool even(int value);
```


```cpp

// include_example.cpp
#include <iostream>
#include "include_example.h"


// On peut appeller les fonctions avant même qu'il soient définie
// Car elle sont dans le fichier entête.

int main() {
    cout << square(15) << endl;
    if (even(42)) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
}

int square(int x) {
    return x * x;
}

bool even(int v) {
    return v % 2 == 0;
}
```
-----------------------



