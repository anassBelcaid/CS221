---
layout : page
title  :  Mastering linked Lists
date   :  2021/06/06  
permalink : /funlinkedlists/
---


    
1. [Linked List pointers](#linkedptr)
    - [Is Sorted](#isSorted)
    - [DoubleIt](#doubleIt)
    - [Expand](#expand)
    
2. [Classic problems](#classic)
    - [Reverse](#reverse)
    - [Split](#split)
    
    

## [Linked List pointers](#linkedptr)
<a name='linkedptr'></a>

### [Is Sorted](#isSorted)
<a name='isSorted'></a>

Dans l'exercice <img src="{{ site.url }}{{ site.baseurl }}/assets/logo_step.png"
width="30" height="30"> [IsSorted]( https://www.codestepbystep.com/problem/view/cpp/collectionimpl/linkedlistptr/isSorted), on vous demande d'écrire une fonction `isSorted` qui reçoit  un **pointeur** sur une noeud d'une
liste qui représente le **head** d'une liste chainée. Votre fonction doit
renvoyer un booléen qui indique si cette liste chainée est **triée** ou non.


```cpp
struct ListNode {
    int data;            //valeur dans chaque noeud
    ListNode *next;      // pointeur sur le noeud suivant
}
```


### [DoubleIt](#doubleIt)
<a name='doubleIt'></a>


Dans l'exercice <img src="{{ site.url }}{{ site.baseurl }}/assets/logo_step.png"
width="30" height="30"> [doubleIt](https://www.codestepbystep.com/problem/view/cpp/collectionimpl/linkedlistptr/doubleList), on vous demande d'écrire une fonction `doubleList` qui reçoit un **pointeur** sur le `head` d'une liste chainée et qui ajoute une **copie** de cette chaine a la fin de celle ci.


Par exemple si la chaine est 

```shell
{ 1, 35, 28, 7}
```

alors l'appel `doubleList(front)` modifiera la liste en:

```shell
{ 1, 35, 28, 7, 1 , 35, 28, 7}
```

**Contraintes**

- Vous ne pouvez pas utiliser des **structure de donnes**  comme un vecteur ou
un string.
- Au maximum vous devez créer $$N$$ noeuds u $$N$$ est le nombre de neouds de la
liste originale.


### [Expand](#expand)
<a name='expand'></a>

Dans l'exercice <img src="{{ site.url }}{{ site.baseurl }}/assets/logo_step.png"
width="30" height="30">
[expand](https://www.codestepbystep.com/problem/view/cpp/collectionimpl/linkedlistptr/expand),
on vous demande d'écrire une fonction `expand` qui reçoit  une **référence** sur
un pointeur `ListNode` représentant la début d'une liste chainée et un paramètre
$$k$$. Cette fonction doit remplacer chaque noeud par $$k$$ copies avec une
valeur $$\dfrac{v}{k}$$.

Par exemple, supposons que la liste initiale est 

```shell
{12, 34, -8, 3, 46}
```

l'appel `expand(L, 2)` changera la liste en 


```shell
{6, 6, 17, 17, -4, -4, 1. 1, 23, 23}
```

Si par exemple, on avait execute `expand(L, 3)`, on aura alors:

```shell
{4, 4, 4, 11, 11, 11, -2, -2, -2, 1, 1, 1, 15, 15, 15}
```


- Si une liste est vide, elle restera vide.
- Si $$k$$ est **négatif**, lancer une exception.
- Si $$k=0$$, **détruire** toute la chaine.

## [Classic problems](#classic)
<a name='classic'></a>


### [Reverse](#reverse)
<a name='reverse'></a>


Le problème <img src="{{ site.url }}{{ site.baseurl }}/assets/logo_step.png"
width="30" height="30">
[reverse](https://www.codestepbystep.com/problem/view/cpp/collectionimpl/linkedlistptr/reverse), vous demande d'écrire une fonction `reverse` qui reçoit une **référence** sur un pointeur **ListNode** et qui renverse l'ordre de cette liste.

Par exemple l'appel sur la liste `{1, 8, 19, 4, 17}` changera la liste en `{17,
4, 19, 8, 1}`.


###  [Split](#split)
<a name='split'></a>

Finalement, dans <img src="{{ site.url }}{{ site.baseurl }}/assets/logo_step.png"
width="30" height="30">
[partition sort](https://www.codestepbystep.com/problem/view/cpp/collectionimpl/linkedlistptr/split), on vous demande d'écrire une fonction `split` qui accepte une **référence** sur un pointeur NodeList et **réarrange** les éléments de cette liste entre nombres positifs et négatifs.

Par exempple, supposons que la liste est 

```shell
{8, 7, -4, 19, 0, 43, -8, -7, 2}
```

Apres l'appel, la liste deviendra 

```shell
{-7, -8, -4, 8, 7, 19, 0, 43, 2}
```

- Remarquer que les nombres positifs garde leur ordre d'apparition.
- Contrairement, l'ordre d'apparition des nombres négatifs est inverse.
