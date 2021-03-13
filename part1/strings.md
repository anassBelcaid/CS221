---
layout : page
title  :  Fonctions
date   :  2021/03/17  
permalink: /strings/
categories:  jekyll updates
---

# Table de matière

1. [Bases](#bases)
    - [Fonctions](#functions).
    - [Structures](#structures)
    - [Includes](#includes).
2. [Strings](#strings1)

    
    


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



## Structures
<a name='structures'></a> 

## Includes
<a name='includes'></a>


-----------------------
## C++ Strings
<a name='strings1'></a>



