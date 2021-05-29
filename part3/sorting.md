---
layout : page
title  : Sorting
date   :  2021/05/31  
permalink : /sorting/
---


## Contents

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/lego-sort.png"
  width="400" height="300">
</div>


1. [Introduction](#intro)
2. [Bubble Sort](#bubble)
    - [Bubble](#bubbleOp)
    - [Invariant and complexity](#compbubble)
    - [repeated Bubble](#rbubble)
3. [Selection Sort](#selectionSort)
    - [Selection](#selection)
    - [Invariant and complexity](#selecInvar)
4. [Insertion Sort](#insertionSort)
    - [insertion](#insertion)
    - [Invariant and Complexity](#compSelection)
    <a name='compSelection'></a>
    
5. [Merge Sort](#mergeSort)
    - [Merging](#merging)
    - [Complexity](#mergeComplexity)

6.  [Quick Sort](#quicksort)
    - [Partition](#partition)
    - [Pivot Choice](#pivot)
    - [Amortized complexity](#amocomplexity)
    <a name='amocomplexity'></a>
    
    
    
    

## [Introduction](#intro)
<a name='intro'></a>

> L'opération de tri ([Sorting](https://en.wikipedia.org/wiki/Sorting_algorithm))
consiste **réarranger** les éléments d'un tableau selon un **ordre** donné.


**Input** : Une séquence (*array*) de nombres $$(a_1, a_2, \ldots , a_n)$$
**Output**: Une permutation (rearangement) $$(a_1^{'}, a_2^{'}, \ldots, a_n^{'})$$ tel que

$$
a_1^{'} \leq a_2^{'} \leq a_3^{'} \leq  \ldots  \leq a_n^{'}
$$


Souvent on se réfère aux valeurs de ce tableau par `Keys`(clés).


## [Bubble sort](#bubble)
<a name='bubble'></a>

Le premier algorithme classique est le [Tri a bulles](https://en.wikipedia.org/wiki/Bubble_sort). Son concept est de faire monter une **plus grande** valeur  ( comme une bulle) à la surface.

Cette opération est réalisée en **permutant** deux clés consécutives s'ils sont
mal ordonnés.



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/Sorting_bubblesort_anim.gif">
  <div class="figcaption">
   Animation du tri a bulles.
  </div>
</div>


### [Bubble](#bubbleOp)
<a name='bubbleOp'></a>

L'opération de base de ce tri, est la montée de bulle. Cette opération consiste
a comparer deux clés successives et de les permuter en cas ou elles sont mal
ordonnes. Voici un fonction qui réalise cette opération entre deux emplacement
mémoire qui dénotent le **début** et fin d'un tableau.


```cpp
void bubble( int * begin, int *end)
{
    /* execute a bubble operation from begin to end (non incluse)
     * begin : pointer on the first memory address
     * end   : pointer on the last memory address
     */

    // initiating a pointer on the first value
    auto curr = begin;

    while( curr < end - 1)
    {
        if ( *curr > *(curr + 1) )
            swap(*curr, *(curr + 1));
        
        curr++;
    }
}
```



### [Invariant and complexity](#compbubble)
<a name='compbubble'></a>

Dans l'analyse des algorithmes de tri, on s'intéresse souvent a la propriétés
`invariant de boucle` qui résume le principe que l'algorithme de tri essaie de
conserver a fin de réaliser le tri. Par exemple pour le tri a bulles ou essaie a
chaque itération de mettre la plus grande valeur a sa place. On aura que:

**Invariant**:

> Après **k** itérations de `bubble`, les $$k$$ plus grandes valeurs seront a
leurs places.


**Corollaire**:

> Après  $$\;n-1$$ itérations de bubble, le tableau sera trié.


### [repeated Bubble](#rbubble)
<a name='rbubble'></a>

Ainsi selon la propriété **invariant de boucle**, le tableau sera trie si on
réalise $$ n-1 $$ opérations de bubble.

```cpp
void bubble_sort(int * begin, int * end)
{
    // function to perform a bubble sort in the array
    // delimited by begin and end
    while(end > begin)
    {
        bubble(begin, end);
        end --;
    }
}
```

Pour l'étude de complexité, soit $$T(n)$$ le nombre d'opérations qu'on doit
effectuer pour trier un tableau de taille $$n$$. Pour ce faire, on doit lancer
$$ n-1$$ opérations de bubble ( la taille de tableau est réduite dans chaque
itération).





$$ 
T(n) =  B(n) + B(n-1) + \ldots + B(2)
$$ 

Où $$ B(n)$$ est le nombre d'opération de la fonction `bubble`. Or on sait que
$$B(n) = n$$. Ainsi on obtient que:


$$ 
T(n) = n + (n-1) + \ldots + 2 \leq \dfrac{n(n+1)}{2} =  \mathcal{O}(n^2)
$$


##  [Selection Sort](#selectionSort)
<a name='selectionSort'></a>

###  [Selection](#selection)
<a name='selection'></a>

### [Invariant and complexity](#selecInvar)
<a name='selecInvar'></a>

##  [Insertion Sort](#insertionSort)
<a name='insertionSort'></a>


###  [insertion](#insertion)
<a name='insertion'></a>

### [Invariant and Complexity](#compSelection)
<a name='compSelection'></a>

## [Merge Sort](#mergeSort)
<a name='mergeSort'></a>

###  [Merging](#merging)
<a name='merging'></a>

### [Complexity](#mergeComplexity)
<a name='mergeComplexity'></a>

##  [Quick Sort](#quicksort)
<a name='quicksort'></a>

### [Partition](#partition)
<a name='partition'></a>

#### [Pivot Choice](#pivot)
<a name='pivot'></a>


### [Amortized complexity](#amocomplexity)
<a name='amocomplexity'></a>
