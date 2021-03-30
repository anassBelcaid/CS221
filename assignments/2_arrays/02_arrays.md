---
layout : page
title  : Practice Session (Arrays)
date   :  2021/03/30  
permalink: /arrayproblems/
---



<div class="figcenter">
<img 
    src="{{ site.url }}{{ site.baseurl }}/assets/vectors/banner.png"
    width="300"
    height="300">
</div>

L'objectif de session est de traiter une collection de problèmes sur les
**tableau** et les **matrices** pour renforcer votre compréhension de leurs
opérations basiques:

- Maitriser les déclarations et nature d'un tableau basique en **C++**.
- Utiliser efficacement la collection `vector`.
- Se familiariser avec les containers de **Stanford** comme `Vector` et `Grid`.


## Overview

1. [Raw Array](#arrays)

    - [Array Mystery1](#arrayMystery1)
    - [Array Mystery2](#arrayMystery2)
    - [Array Mystery3](#arrayMystery3)
    - [Banish](#banish)
    

2. [Vectors](#vectors)
    - [Collection Mystery1](#vectorMystery1)
    - [Comulative](#cumulative)
    - [Histogram](#histogram)

3. [Grids](#grids)
    - [CrossSum](#crosssum)
    - [Flatten](#flatten)
    - [Swap](#swap)
    - [multTable](#multtable)




## [Raw Arrays](#arrays)
<a name='arrays'></a>


Section pour traiter des tableaux simples (sans la classe **vector**).


### [Array Mystery1](#arrayMystery1)
<a name='arrayMystery1'></a>

On considère le problème [ArrayMystery](https://www.codestepbystep.com/problem/view/cpp/arrays/arrayMystery) où, on nous donne la fonction suivante:

```cpp
void mystery(int list[], int lenght)
{
    for(int i = 1; i < length; i++)
        list[i] = list[i] + list[i - 1];
}
```


Pour chaque entrée, indiquer les valeurs du tableau après l'appel de la
fonction.


```shell
1. {8}
2. {6, 3}
3. {2, 4, 6}
4. {1, 2, 3, 4}
5. {7, 3, 2, 0, 5}
```


### [Array Mystery2](#arrayMystery2)
<a name='arrayMystery2'></a>

On considère le problème [ArrayMystery](https://www.codestepbystep.com/problem/view/cpp/arrays/arrayMystery2) où, on nous donne la fonction suivante:

```cpp
void mystery2(int list[], int lenght)
{
    for(int i = 0; i< length - 1; i++)
        if(i % 2 == 0)
            list[i]++;
        else
            list[i]--;
}
```


Pour chaque entrée, indiquer les valeurs du tableau après l'appel de la
fonction.


```shell
1. {6, 3}
2. {2, 4, 6}
3. {1, 2, 3, 4}
4. {2, 2, 2, 2, 2}
5. {7, 3, 2, 0, 5, 1}
```



### [Array Mystery3](#arrayMystery3)
<a name='arrayMystery3'></a>

On considère le problème [ArrayMystery](https://www.codestepbystep.com/problem/view/cpp/arrays/arrayMysteryExam2) où on nous donne la fonction suivante:


```cpp
void arrayMystery(int a[], int length)
{
    for(int i=0; i < length - 1; i++)
        if ( a[i] > a[ i + 1])
        {
            int temp = a[i];
            a[i]  = a[i+1];
            a[i+1] = temp;
            a[0]++;
        }
}

```


Pour chaque entrée, indiquer les valeurs du tableau après l'appel de la
fonction.


```shell
1. {5, 2, 5, 2}
2. {30, 10, 20 ,50, 40}
3. {99, 88, 77, 66, 55, 44}
```


### [Banish](#banish)
<a name='banish'></a>

On considère l'exercice [Banish](https://www.codestepbystep.com/problem/view/cpp/arrays/banish) où on nous demande d'écrire une fonction `banish` qui reçoit deux vecteurs d'entiers $$a_1$$ et $$a_2$$ et leurs longueur comme paramètre. Puis la fonction **supprime** toutes les occurrences de $$a_2$$ du vecteur $$a_1$$.

> Un élément est supprimé est **déplaçant** tous les élément à sa droite puis
un **insérant un 0** à la place vacante.


Par exemple

```cpp
int a1[] = {42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1};

int a2[] = {42, 2222, 9};

banish(a1, 17, a2, 3);
```

```
Après l'appel le vecteur $$a_1$$ sera:

```shell
a_1 = {3, 0, 17, 8, 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
```






## [Vectors](#vectors)
<a name='vectors'></a>


### [Collection Mystery1](#vectorMystery1)
<a name='vectorMystery1'></a>

Dans le problème [Collection Mystery1](https://www.codestepbystep.com/problem/view/cpp/collections/vector/collectionMystery1), on considère la fonction utilisant la classe **Vector**

```cpp
void collectionMystery1(Vector<int> & list)
{
    for(int i=0; i< list.size(); i++)
    {
        int n = list[i];

        list.remove(i);

        if( n % 2 == 0)
            list.add(i);
    }
}
```


Quel sera l'état de chaque vecteur listé après l'appel de cette fonction.

```shell
1. {5, 2, 5, 2}
2. {3, 5, 8, 9, 2}
3. {0, 1, 4, 3, 1, 3}
```




### [Cumulative](#cumulative)
<a name='cumulative'></a>

Dans le problème [Cumulative](https://www.codestepbystep.com/problem/view/cpp/collections/vector/cumulative), votre tache est d'écrire une fonction `cumulative` qui reçoit une **reference**  à un **Vector** d'entiers qui le modifie en **cumulant** la somme des éléments visités. 

$$
A_j = \sum_{i=0}^{j} A_i
$$

Par exemple si on reçoit le tableau 

```shell
{1, 1, 2, 3, 5}====> {1, 2, 4, 7, 12}
```


### [Histogram](#histogram)
<a name='histogram'></a>

Le but du problème [Histogram](https://www.codestepbystep.com/problem/view/cpp/collections/vector/histogram) est d'écrire une fonction `histogram` qui accepte une **référence** d'un tableau d'entiers. Ce tableau contient les notes qui sont dans la rangée $$[0-49]$$. 

Cette fonction doit afficher un **histogramme** groupé par $$10$$. Par
exemple pour le tableau $$\{48, 20, 31, 49, 35, 45, 33, 26, 48, 32, 19\}$$, la
fonction doit afficher


```
0's : {}
10's : {19}
20's : {20, 26}
30's : {31, 35, 33, 32}
40's : {48, 49, 45, 48}
```



## [Grids](#grids)
<a name='grids'></a>


### [CrossSum](#crosssum)
<a name='crosssum'> </a>

Dans le problème [Cross Sum](https://www.codestepbystep.com/problem/view/cpp/collections/grid/crossSum), on nous demande d'écrire une fonction
nommée `crossSum` qui reçoit une **rérérence** sur un grille et deux indices
**row** et **col**. Cette fonction doit renvoyer la somme de la ligne **row** et
la colonne **col** ( sans répétition).


Par exemple, pour la matrice

```
G = ((1,2,3),
     (4,5,6),
     (7,8,9))
```

et les valeurs `row=1`, `col=1`, la fonction doit renvoyer  `2+5+8+4+6`



### [Flatten](#flatten)
<a name='flatten'></a>

Le but de l'exercice [Flatten](https://www.codestepbystep.com/problem/view/cpp/collections/grid/flatten) et de contruire un vecteur à partir d'une matrice (Grid).Ainsi, on vous demande d'écrire une fonction `flatten` qui reçoit une référence sur une Grille **G** et construit un `Vector` en regroupant les éléments de $$G$$ **ligne par ligne**.

Par exemple pour l'appel de la fonciton sur la matrice suivante:

$$
\begin{pmatrix}
3 & 8 & 12\\
2 & 9 & 17\\
43 & -8 & 46\\
203 & 14 & 97
\end{pmatrix}
$$


renvoie le vecteur $$V=(3, 8, 12, 2, 9, 17, 43, -8, 46, 203, 14, 97)$$.


### [Swap](#swap)
<a name='swap'></a>


Pour l'exercice  [Swap](https://www.codestepbystep.com/problem/view/cpp/collections/grid/mirror), on vous demande d'écrire une fonction `mirror` qui accepte une référence sur un **Grid** $G$ qui est carré et qui la **permute** dans le sens de la diagonale principale.


$$
\begin{pmatrix}
1& 4 & 5\\
3 & 8 & 9\\
1 & -2 & 11
\end{pmatrix}
\Longrightarrow

\begin{pmatrix}
1& 3 & 1\\
4 & 8 & -2\\
5 & 9 & 11
\end{pmatrix}
$$


### [multTable](#multtable)
<a name='multtable'></a>

L'exercice [mult Table](https://www.codestepbystep.com/problem/view/cpp/collections/grid/multTable) vous demande d'écrire une fonction `multTable` qui reçoit une référence sur une grille $$G$$ et un entier **max** et qui remplie cette grille par les éléments de la **table de multiplication**.

Par exemple pour l'appel de la fonction avec $$max=5$$, on aura la grille suivante:

```
   col    0  1  2  3  4
row
 0      { {0, 0, 0, 0, 0},
 1       {0, 1, 2, 3, 4},
 2       {0, 2, 4, 6, 8},
 3       {0, 3, 6, 9, 12},
 4       {0, 4, 8, 12, 16} }
 ```
