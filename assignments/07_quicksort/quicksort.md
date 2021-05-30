---
layout : page
title  : Quick Sort
date   :  2021/05/03  
permalink : /quicksort/
---


1. [Quick Sort](#quicksort)
    - [Partition Function](#partition)
    - [quick sort](#quick)
    <a name='quick'></a>
    
    


## [Quick Sort](#quicksort)
<a name='quicksort'></a>

Le tri rapide `Quick sort` est un algorithme de tri formule par **Tony Hoare**
qui possède une complexité **amortie** $$ \mathcal{O}(n\log\;n)$$. Dans le pire
    cas il peut avoir une complexité quadratique $$\mathcal{O}(n^2)$$. Tous les
    langages l'utilisent comme tri de **référence**.


Ce tri suit aussi l'approche `diviser pour regner` qui commence par
**segmenter** le tableau autour d'un **pivot** choisi par parmi les valeurs du
tableaux. La `segmentation` consiste a mettre tous les éléments infère rieurs au
pivot  gauche et ceux supérieurs a droite. Une fois terminer on est sur que le
**pivot** occupe sa place dans le tableau trié et il suffit juste de trier les
deux parties ( droite et gauche).


<div class="fig figcenter fighighlight">
<img src="{{ site.url }}{{ site.baseurl}}/assignments/07_quicksort/partion_mecanism.png">
  <div class="figcaption">
  Principe de partition d'un tableau.
  </div>
</div>


### [Partition Function](#partition)
<a name='partition'></a>

On peut réaliser facilement cette opération si on possède un nouveau tableau.
Cependant il existe méthode très simples pour réaliser cette partition
`in-place` ( sans avoir a utiliser un autre tableau). 

> Votre défi consiste a développer cette fonction puis l'utiliser pour
implémenter le tri rapide.

Pour ce faire on va utiliser la notation suivante:


- `p` est l'adresse du premier élément dans le tableau.
- `r` est l'adresse du dernier élément du tableau qui constitue notre pivot.
- `i` est un pointeur qui vérifie que tous les éléments a sa gauche sont
**inférieurs** au pivot.
- `j` est pointeur qui vérifie que tous les éléments a sa gauche sont
**supérieurs** au pivot.
- Les éléments entre `j` et `r` sont a traités.

Le schéma de cette partition est illustrée dans la figure suivante.

<div class="figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/07_quicksort/quick_sort.png">
</div>


Dans le projet <a href="{{ site.url }}{{site.baseurl}}/assignments/07_quicksort/quicksort.zip"> quickSort.zip</a>, vous trouverez le code de départ qui contient des tests pour ce tri. Votre première tache consiste a **implémenter** la fonction 


```cpp
int partition( int *begin, int * end)
```

Où

- `begin` est un pointeur sur la première adresse du tableau.
- `end` est un pointeur sur la dernier adresse du tableau.
- La fonction doit renvoyer la position  finale du pivot.



### [quick sort](#quick)
<a name='quick'></a>


Maintenant que vous disposez d'une fonction de **partition** opérationnelle,
implémenter une fonction récursive `quicksort` selon le premier schéma.

La fonction possède le prototype suivant:

```cpp
void quickSort( int *begin, int *end)
```

Ou

- `begin` est un pointeur sur le premier élément.
- `end` est un pointeur sur le dernier élément.

> Vous devez maintenant passer tous les tests de ce code.
