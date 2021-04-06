---
layout :  page
title  :  Working with pointers
date   :  2021/04/04  
permalink : /asspointers/
---


## Liste d'exercice.


1. [Grasping](#grasping)
    - [v1v2p1p2](#v1v2p1p2)
    - [parameterMystery1](#parmystery1)
    - [parameterMystery2X](#parmystery2)

2. [Arrays using pointers](#arrays)
    - [Pivot Index](#pivotIndex)
    - [Largest Number](#largestNumber)
    - [Plus One](#PlusOne)

## [Grasping](#grasping)
<a name='grasping'></a>


## [V1V2P1P2](#v1v2p1p2)
<a name='v1v2p1p2'></a>

Dans l'exercice
[v1v2p1p2](https://www.codestepbystep.com/problem/view/cpp/pointers/v1v2p1p2),
on vous demande d'éxécuter le programme suivant et de donner leur **résultat**.

```cpp
int v1 = 10;
int v2 = 25;
int *p1 = &v1;
int *p2 = &v2;

*p1 += *p2;
p2 = p1;
*p2 = *p1 + *p2;

cout<< v1 << " " << v2 << endl;
cout<< *p1 <<" " << *p2 << endl;
```


## [parameterMystery1](#parmystery1)
<a name='parameterMystery1'>

Dans l'exercice [ParameterMystery1](https://www.codestepbystep.com/problem/view/cpp/pointers/parameterMystery1), on vous demande de produire le résultat du programme suivant:

```cpp
int parameterMystery1(int a, int &b, int* c)
{
 b++;
 a += *c;

 cout<< b << " "<< *c<< " " << a << " " << c << endl;

 c = &a;
 return a-b;
}

int main()
{
  int a = 4;
  int b = 8;
  int c = -3;
  int d;

  d = parameterMystery1(a, b, &c);

  parameterMystery1(c, d, &b);
  parameterMystery1(b, a, &d);

  cout<< a <<" " << b << " " << c <<" " <<d << endl;
}
```

Pour unifier le résultat, on suppose que les les variables sont stockées dans
les mémoires suivantes:

- a est stockée dans `0xaa00`
- b est stockée dans `0xbb00`
- c est stockée dans `0xcc00`
- d est stockée dans `0xdd00`

## [parameterMystery2X](#parmystery2)
<a name='parmystery2'>

Similaire à l'exércice précédant, dans
[ParamterMyster2](https://www.codestepbystep.com/problem/view/cpp/pointers/parameterMystery2X),
on vous demande de produire le résultat du programme suivant:


```cpp
string * parameterMyster2X(string & s1, string s2)
{
    s1 += "1";
    s2 += "2";

    cout<< s2 << " -- " << s1 <<endl;
    s1 += "!!!";

    return &s1;
}

int main()
{
    string s1 = "hi";
    string s2 = "bye";
    string s3 = "yo";

    string * s4 = new string(s3);
    string* s5 = nullptr;

    parameterMyster2X(s1, s3);
    s5 = parameterMyster2X(*s4, s2);
    parameterMyster2X(s2, *s5);

    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    cout<<s4<< " " << *s4 << " " << s5 << *s5 << endl;
}
```

Les espaces mémoires des variables est le suivant:

- s1 est dans `0x1100`
- s2 est dans `0x2200`
- s3 est dans `0x3300`
- s4 est dans `0x4400`
- s5 est dans `0x5500`




## [Arrays using pointers](#arrays)
<a name='arrays'>

Il est temps d'utiliser vos connaissances en **Tableau** et `pointeur` pour
résoudre des problèmes un peu plus difficile. Dans la suite on vous fournit un
projet `cmake` qui contient un fichier pour chaque exercice. Le projet
nécessite la bibliothèque `google test`.

En cas où vous n'arrivez pas à l'exécuter, enlever lest fonctions `test`, et
remplacez les par vos propre tests.




### [Pivot Index](#pivotIndex)
<a name='pivotIndex'>

Etant donné un tableau d'entiers `nums`, calculer son **indice pivot**. 

> L'indice pivot d'un tableau est où la somme des éléments à sa stricte gauche
est **égale** à la somme de ceux qui sont à la stricte droite.

- Si l'indice est $$0$$, alors la somme à gauche est considérée **nulle**.
- De même, pour l'indice à la fin, la somme a droite est **nulle**.

Ecriver une fonction qui possède le prototype suivant:

```cpp
int pivotIndex( vector<int> & nums)
{

}
```

La fonction doit renvoyer le **premier** indice pivot. En cas où on ne trouve
aucun indice, on revoit la valeur $$-1$$.



**Exemple 1**

```
Input: nums = [1,7,3,6,5,6]
Output: 3
Explication:
La valeur du pivot est 3.
Somme gauche = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Somme droite = nums[4] + nums[5] = 5 + 6 = 11
```

**Exemple 2**

```
Input: nums = [1,2,3]
Output: -1
Explication:
Il n y'as aucun indice qui vérifie cette condition
```

**Exemple 3**

```
Input: nums = [2,1,-1]
Output: 0
Explication
L'indice pivot est 0.
Somme gauche = 0 (Pas d'élément à gauche de 0)
Somme droite = nums[1] + nums[2] = 1 + -1 = 0
```


Le fichier avec les tests est dans `array_pivot.cpp`.


### [Largest Number](#largestNumber)
<a name='largestNumber'>

Etant donné un vecteur des entiers `nums`, Trouver le plus grand élément dans ce
tableau. 

> Votre tache est de confirmer si c'est élément est **au moins** plus grand que le double du reste. Si c'est le cas vous renvoyer son indice, sinon vous renvoyer -1.


> Le vrai défi, est de réaliser ce exercice avec des pointeurs avec juste une
**seule** passe du tableau.


**Exemple1**

```shell
Input: nums = [3, 6, 1, 0]
Output: 1
Explication: 6 est le plus grand eniter, et pour chaque valeur dans le tableau
x, 6 est supérieur ou égal au double de x
```

**Exemple 2**


```shell
Input: nums = [1, 2, 3, 4]
Output: -1
Explication: 4 est inférieur au double de 3.
```


Vous trouverez le code de départ dans `largest_number.cpp`.

### [Plus One](#PlusOne)
<a name='PlusOne'>

Etant donné un tableau **stl**   `non vide` qui représente les chiffres d'un
entier positive $$n$$. Votre tache est de renvoyer une tableau **stl** qui
contient les chiffres de $$n+1$$.


Le prototype  de  la fonction est le suivant:

```cpp
vector<int> plusOne(vector<int> & nums)
{

}
```

**Exemple 1**:

```
Input: digits = [1,2,3]
Output: [1,2,4]
```


**Exemple 2**:


```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
```

**Exemple 3**:


```
Input: digits = [0]
Output: [1]
```


Vous trouvez le code de départ dans `add_one.cpp`.
