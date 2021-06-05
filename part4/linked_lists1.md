---
layout : page
title  : Linked Lists
date   :  2021/06/0updates
permalink : /linkedlists1/
---

<div class=" figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/linked_lists_logo.png"
  width="500" height="200">
</div>



## Contents


1. [Introduction](#intro)
2. [Structure](#structure)
3. [Add Operation](#addop)
    - [Adding at the Beginning](#addbegin)
    - [Ading at a given index](#addIndex)
4. [Delete Operation](#delete)

5. [LL class design](#classdesign)
6. [Two Pointers](#twopointers)
    - [Detect cycle](#cycle)
    <a name='cycle'></a>
    

 


## [Introduction](#intro)
<a name='intro'></a>

Dans ce chapitre, nous tournons attention à une autre **structure de données**
appelée  **Liste chainés** `Linked Lists`. Il s'agit d'une structure
**linéaire** ou chaque élément connait l'adresse de son successeur.

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/sample_linked_list.png" height="80">
  <div class="figcaption">
  Illustration d'une Lined Lists où chaque élément connait l'adresse (pointe) de son successeur.
  </div>
</div>

Comme illustré dans la figure précédente, la structure d'une liste chainée
comporte plusieurs `noeuds` **nodes** qui sont liés entre eux par des
**pointeurs** ( ou références) sur l'élément suivant.


 Il existe deux types de listes chainées:
 - `Singly Linked Lists`: Chaque nœud connait seulement l'adresse de son
 successeur.

 - `Doubly linked Lists`: Un noeud connait non seulement l'adresse de son
 successeur mais aussi de son prédécesseur. 


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/doubley_linked_lists.png" height="80">
</div>


L'objectif de ce chapitre est de:

- Comprendre la **structure** d'une liste chainée.
- Implémenter la traversée, l'insertion et la suppression d'un élément.
- Analyser la complexité de ces opérations.
- Utiliser la technique des **deux pointeurs** dans des listes chainés.


##  [Structure](#structure)
<a name='structure'></a>

Nous commençons a analyser la structure d'une liste chaines simples (`Singly
Linked List`). On peut remarquer que cette structure contient une **sequence**
de noeuds. Chaque noeud contient:

- Une **valeur** 
- Un **pointeur** (flèche bleu) sur l'élément suivant.

Ainsi on peut developper une `structure` pour stocker les informations de ce
neoud.


```cpp
// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    //Constructor
    SinglyListNode(int x) : val(x), next(NULL) {}
};
```

> Pour représenter toute la liste, nous allons utiliser le nœud `head` qui se
réfère au **premier** nœud de la liste.


Un point important a remarquer (compare aux vecteurs), est qu'on vient de
**perdre** l'accès direct aux éléments. Par exemple dans la figure précédente,
si on veut accéder a l'élément $$15$$ est de **traverser** toute la liste.

Ainsi pour cette structure, il nous faut une `complexite lineaire`
$$\mathcal{O}(N)$$ juste pour accéder  a un élément.


> Une question qu'on doit se poser est pourqu'oi on utilise une telle structure
avec un tel inconvénient. La réponse réside dans les deux opérations de
**ajout** et de **suppression**.

## [Add Operation](#addop)
<a name='addop'></a>

Nous tournons note attention a l'opération principale d'une liste chainée. On va
considérer un nœud `prev` et on cherche a **ajouter** une valeur juste après ce
nœud.

<center>
 <font size="+3">Toujours, Toujours construire un schéma qu'on vous implémenter
 une liste chainée.</font>
</center>

###  [Ading at a given index](#addIndex)
<a name='addIndex'></a>

1. Initialiser un noeud `curr` avec la valeur a insérer.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/insertion1_step1.png"
  height="150">
</div>

2. Lier le pointeur de `curr` au successeur de `prev`.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/insertion1_step2.png"
  height="150">
</div>

3. Lier le pointeur de `prev` au noeud `curr`.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/insertion1_step3.png"
  height="150">
</div>


> Comme illustré dans le schéma, on peut réaliser cette opération dans un
**temps constant** $$\mathcal{O}(1)$$ sans soucier de la capacité (dans les
tableaux).  Ceci consiste un avantage majeur par rapport aux vecteurs.



#### Exemple:

Considerons la liste chainée suivante:


<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/SLL_example-step0.png"
  height="80">
</div>

Nous allons insérer la valeur $$9$$ après $$6$$.

Il faut alors construire un noeud avec la valeur $$9$$, Lier le $$9$$ a $$15$$.
Puis il faut lier le noeud $$6$$ au noeud $$9$$.


<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/SLL_example-step1.png"
  height="100" width="400">
</div>


### [Adding at the Beginning](#addbegin)
<a name='addbegin'></a>

L'algorithme d'insertion change si on considère l'ajout au **début de la
chaine**. Puisque on doit maintenir la référence `head` sur le début de la liste
chainée. Ainsi pour ajouter un noeud au début on doit:


1. Initialiser le noeud `curr`.
2. Lier le noeud `curr` a `head`. 
3. Mettre a jour `head`.


Pour illustrer ce principe, ajouter le noeud $$9$$ a notre liste:

1. Créer un noeud `curr` avec la valeur $$9$$ et le lier a $$23$$.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/insertion2_step0.png"
  height="100" width="400">
</div>

2. Mettre a jour `head` au neoud $$9$$.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/insertion2_step1.png"
  height="100" width="400">
</div>

> Une question qui se pose est la possibilité d'utiliser la même technique pour
insérer un noeud a la **fin**.

##  [Delete Operation](#delete)
<a name='delete'></a>

Similaire a l'ajout, on peut **supprimer** un noeud `curr` de la liste chainée,
en deux opérations.


1. Trouver le **predecesseur**  de `curr`.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/deletion1_step1.png"
  height="100">
</div>


2. Lier le noeud `prev` et `next`.

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/deletion1_step2.png"
  height="100">
</div>

Si on analyse la complexité de cette operation.

1. On connait déjà la référence `next` du noeud `curr`.
2. Cependant pour accéder a `prev`, il faut parcourir la liste pour trouver de
   noeud.

> Ainsi la complexité, de cette opération sera **linéaire** $$\mathcal{O}(N)$$
pour une liste simple.



#### Exemple:

Soit la liste:

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/sample_linked_list.png"
  height="80">
</div>


- On cherche a supprimer le noeud $$6$$.
- Traverser la liste pour trouver le predecesseur de $$6$$ qui est $$23$$.
- Lier $$23$$ (`prev`) a $$15$$ (`next`).

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/deletion2_step2.png"
  height="80" width="400">
</div>


Similaire a l'insertion, la suppression doit être adaptée pour la suppression du
**premier** élément.

Pour supprimer le premier noeud `head`, il suffit de le déplacer, 

1. Considerson la suppression du premier noeud

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/delection3_step1.png"
  height="80" width="400">
</div>


2. Maintenant $$6$$ devient `head` maintenant:

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part4/images/delection3_step2.png"
  height="80" width="400">
</div>

> Réfléchir a la question de suppression du **élément**.

## [LL class design](#classdesign)
<a name='classdesign'></a>

Il est temps d'**implémenter** la classe `Linked List` avec les operations qu'on
as présenter.


Dans le <a href="{{ site.url }}{{site.baseurl}}"> singly_linked_list.zip</a>,
vous devez completer la classe `LinkedList` avec les membres suivants:

- `LinkedList` : initialise la liste chainée.
- `int get(int index)`: renvoie la valeur dans l'indice $$i$$. Si l'indice est
**invalide**, renvoyer $$-1$$.
- `void addAtHead(int val)` ajouter le noeud au début de la liste. 
- `void addAtTail(int val)`: ajouter la valeur **val** a la fin de la liste.
- `void addAtTail(int index, int val)`: ajouter la valeur **val** a l'indice
**index**.
- `void deleteAtIndex(int index)` : **supprime** le noeud dans la position
**index**.
- `operator<<` : afficher la liste chainée.


## [Two pointers](#twopointers)
<a name='twopointers'></a>


### [Detect cycle](#cycle)
<a name='cycle'></a>
