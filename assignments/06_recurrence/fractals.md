---
layout : page
title  :  
date   :  2021/05/18  
permalink : /fractals/
---

<div class="fig figcenter ">
  <img src="{{ site.rul }}{{ site.baseurl }}/assignments/06_recurrence/sierpensky.png">
</div>



## RoadMap

1. [Step By Step ](#step)
    - [IsPalindrome](#palindrome)
    - [Combin](#combin)
    - [CountBy](#count)
    <a name='count'></a>
    
    
2. [Number of Partitions](#partitions)

3. [Fractals](#fractals)


 


## [1. Step By Step ](#step)
<a name='step'></a>

### [IsPalindrome(*)](#palindrome)
<a name='palindrome'></a>

Dans ce premier exercice, on vous demande d'écrire une fonction **récursive**
qui vérifie si une chaine `sring` est **Palindrome** ou non.

> Une chaine est palindrome si elle se lit de droite a gauche comme de gauche a
droite.

Par exemple la chaine `madam` est palindrome.


Voici le lien  <img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[isPalindrome](https://www.codestepbystep.com/problem/view/cpp/recursion/isPalindrome) de l'exercice.

**Contraintes**:

1. Vous ne pouvez pas utiliser des variables **globales**.
2. Vous ne pouvez pas utiliser des **boucles**.
3. Vous ne pouvez ajouter **structures auxiliaires** comme un tableau.
4. Vous devez **ignorer la casse**. i.e ne faite pas la différence entre majuscule
   et minuscules.


### [CountBy(**)](#count)
<a name='count'></a>

Cet exercice vous demande d'écrire une fonction récursive `countToBy` qui
reçoit deux entiers $$n$$ et $$m$$ et qui affiche une séquence qui saut par
$$m$$ jusqu'à atteindre $$n$$. Voici une liste d'exemples pour comprendre
cette fonction:

```cpp
// compter jusqu'a 10 en sautant par 1
countToBy(10, 1);  // affichera 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

// compter jusqu'a 30 en sautant par 4
countToBy(30, 4); // affichera 2, 6, 10, 14, 18, 22, 26, 30
```


> Noter qu'on commence par forcement par $$1$$. Par exemple dans le deuxième
appel, on a commence par 2 pour pouvoir atteindre exactement 30 a la fin!!


Voici le lien  <img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[countToBy](https://www.codestepbystep.com/problem/view/cpp/recursion/countToBy) de l'exercice.

> En cas ou $$m$$ ou $$n$$ sont strictement inférieur a $$1$$, vous devez
envoyer une `exception` entière e.


Par exemple si la valeur finale notée $$n$$ est inférieure a 1, on exécute le
code suivant:

```cpp
//lancer une exception en cas ou n est inferieur a 1
if ( n < 1)
    throw n;
```



### [Combin (***)](#combin)
<a name='combin'></a>

Dans ce défi, on vous demande d'écrire une fonction **récursive** `combin` qui accepte deux
entiers **n** et **k** et qui renvoie le nombre de `combinaison` $$ C_n^k$$.

On rappelle que la formule de cette combine est donne par:

$$
C_n^k = \dfrac{n!}{k!(n - k)!}
$$

Malheureusement, cette définition ne vas vous aider dans extraire la relation de
récurrence. Visiter cette [page Wikipedia](https://en.wikipedia.org/wiki/Combination) pour voir la liste de formules utiles. 

Voici le lien de l'exercice avec des tests: 
<img src="{{ site.rul }}{{ site.baseurl }}/assets/logo_step.png" width="30"
heigth="30">
[Combin](https://www.codestepbystep.com/problem/view/cpp/recursion/combin).

> Ce défi est difficile et nécessite la technique de **Memoization** presentee
dans la lecture. 





## [2. Number of Partitions (**)](#partitions)
<a name='partitions'></a>

On définit `nombre de partitions` d'un entier positif $$n$$ en utilisant au max
 $$m$$ comme le nombre d'**alternatives** pour décomposer $$n$$ en une somme de
 nombres inférieur a $$m$$ en séquence **croissante**.

Prenons par exemple l'entier $$n=6$$ et la partie max $$m=4$$. Alors on peut
trouver $$\mathbf{9}$$ façons pour décomposer $$n$$. Voici la liste de ces
décomposition:


```shell
1. 6 = 2 + 4
2. 6 = 1 + 1 + 4
3. 6 = 3 + 3
4. 6 = 1 + 2 + 3
5. 6 = 1 + 1 + 1 + 3
6. 6 = 2 + 2 + 2
7. 6 = 1 + 1 + 2 + 2
8. 6 = 1 + 1 + 1 + 1 + 2
9. 6 = 1 + 1 + 1 + 1 + 1 + 1
```

Votre tâche (si vous l'acceptez) consiste a écrire une fonction
`count_partitions(n, n)` qui renvoie le nombre de partitions comme expliqué.


Dans le projet <a href="{{ site.url }}{{ site.baseurl }}/part3/partitions.zip">
partitions.zip </a>, vous trouver le code de départ avec des tests unitaires
qui vous de devez passer. 


> Indice 1: Essayez de proposer une récurrence sur $$m$$ qui représente le
nombre maximal pour un terme dans la somme.

> Indice 2: Dans l'exemple précédant, quel est la différence entre les **deux
premiers** lignes et le reste? 

## [3. Fractals](#fractals)
<a name='fractals'></a>
