---
layout : page
title  : Introduction to Recurrence
date   :  2021/05/17  
categories:  jekyll updates
permalink : /recurrence/
---



<div class="figcenter">
<img src="{{ site.url }}{{ site.baseurl }}/part3/images/recursion-recursion.png"
width="400" height="300">
</div>


1. [Towers of Hanoi](#hanoi)
2. [What is Recursion](#definition)
 - [Why Recursion](#why)
 - [Counting People](#counting)
 - [The Three Must](#must)
3. [Basic Examples](#examples)
  - [Factorial](#factorial)
  - [Power of X](#power)
  - [Greated Common Divisor](#pgcd)
  - [combination](#combin)
4. [Memoization](#memoization)
5. [Complexity Analysis](#complexity)



## [Towers of Hanoi](#hanoi)
<a name='hanoi'></a>


Le problème de [**Tour de Hanoi**](https://fr.wikipedia.org/wiki/Tours_de_Hano%C3%AF) est un problème classique qui demande a l'utilisateur de déplacer 
un ensemble de **disques** entre des tiges selon les règles suivantes:

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/Tower_of_Hanoi.jpeg">
  <div class="figcaption">Modèles de tour de Hanoi avec 8 disques.</div>
</div> 


1.  L'objectif est de **déplacer tous les disques** d'une tige initiale a une
    autre.
2. On ne peut déplacer **qu'un disque** a la fois.
3. On  ne peut déplacer un disque sur un autre **plus grand**.

> Peut on résoudre ce problème? Si oui comment?

- Il s'avère qu'il existe une solution mathématique a ce problème.
- La preuve donne exactement la méthode pour résoudre ce problème.

> En cas, ou vous n'êtes pas convaincu, voici une [demo](https://www.mathsisfun.com/games/towerofhanoi.html) qui montre la solution.


<div class="fig figcenter fighighlight">
<iframe src="{{ site.url }}{{ site.baseurl }}/part3/images/Towers-of-Hanoi.m4v"
width="600" height="300">
</iframe>
  <div class="figcaption"> Vidéo illustrant la solution du problème de tour de
  Hanoi pour 5 disques.</div>
</div> 


> Comment peut on résoudre ce problème avec les processus classiques. 

A ce stade, on connait qu'une solution **récursive** a ce problème!!. Si vous n'êtes pas convaincu, essayez de fournir une solution itérative!!!

> A la fin, de cette lecture, vous pouvez proposer une solution simple et
**élégante** a ce problème.


## [What is Recursion](#definition)
<a name='definition'></a>

> La [**récurrence**](https://en.wikipedia.org/wiki/Recursion) est une technique pour résoudre un problème en le **réduisant**
a des simples de problèmes de la même nature.

On peut se demander, comment peut on résoudre un probleme en invoquant le même
problème. L'astuce consiste a `reduire` la complexité en chaque appel. Cette
réduction continue jusqu'à atteindre un cas simple ou on connait la réponse. Ce
cas est appel `base case`.


### [Why Recursion](#why)
<a name='why'></a>

La **récursivité** offre:

1. Une solution **élégante** est simple.
2. Outil très **puissant** de résolution de problème. 
3. **Maitriser** le flux d'exécution.

On rencontre plusieurs exemples récursives dans la vie réelle, A titre
d'exemple, on mentionne le `jigsaw puzzle`:

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/hard-jigsaw-puzzle.png" width="500" height="400">
  <div class="figcaption">Comment peut on résoudre ce problème? </div>
</div> 

- Seule procédure possible est celle récursive.
- Trouver un morceau **correcte**, placer le.
- Continuez avec un problème moins simple (contient mois de pièce).


> Afin d'illustrer ces concepts, nous allons illustrer ce par un exemple

###  [Counting People](#counting)
<a name='counting'></a>

> On considere le probleme de calculer le nombre de personnes dans une file.

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/people.png"
  width="400">
</div>

On veut compter le nombre de personne dans cette file. Le problème est que
chaque personne ne peut parler qu'a ceux dans son **voisinage**. Plus
précisément, on fixe les deux règles suivantes:

1. Une personne peut regarder **devant et derrière** lui.
2. Une personne peut demander des questions aux personnes **devant ou derrière**.


> Comment peut on résoudre ce problème?

- **Solution**: Récurrence

1. Chaque personne récupère la réponse de celle derrière lui et la reporte a celle devant lui. 

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/forward_message.png"
  width="400">
</div>

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/backward_message.png"
  width="400">
</div>

```cpp
int countPersons( Person P)
{
    if(noOneBehind(p))
        return 1;
    else
    {
        auto behind = countPersons(P.getBehind());
        
        return behind + 1;
    }
}
```

### [The Three Must](#must)
<a name='must'></a>

Concevoir un programme ou **fonction récursive** nécessite:

- `Cas de base`: Le cas simple ou on peut facilement répondre a la question.

> Par exemple, dans le cas de calcul du nombre de personnes, la personne a la 
**fin** connait qu'il y as personne derrière lui.

- `Relation de récurrence`: Plus complique a générer, elle consiste le cœur
de la réduction du problème. Elle décrit le problème en terme de problèmes de
même type mais moins complique.

> Dans exemple de calcul des personne, la relation de récurrence indique
simplement que le nombre de personnes sera $$1$$ plus le nombre de personne
**derrière moi**.


Ainsi pour concevoir une fonction **récursive**, il faut assurer que votre code:

1. Votre Code doit une cas pour **tous** les arguments. 
2. Vous devez avoir un **cas de base**.
3. Votre relation de **récurrence** doit générer un appel **plus simple**.

> Pour le reste, vous devez avoir un foi que votre code va donner le bon resulat
:)


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/part3/images/leap-of-faith.png"
  width="600" height="400">
  <div class="figcaption"> The leap of faith.</div>
</div> 


## [Basic Examples](#examples)
<a name='examples'></a>

Cette section introduit des exemples classiques pour apprendre le paradigme de
**récurrence**. C'est votre entrée principale pour se familiariser avec tous
les `concepts` de ce paradigme:


### [Factorial](#factorial)
<a name='factorial'> </a> 

Considérons comme premier exemple, le calcul du **factoriel** d'un entier
naturel $$n$$. 

$$
n! = n \times (n-1) \times (n-2) \ldots 3 \times 2 \times 1
$$




On connait déjà comment implémenter une fonction `iterative` de cette fonction,
cependant dans cet exercice, on veut concevoir une fonction `recursive`.

On va proposer **trois** versions erronés afin que vous puisez identifier les
points manquants soulevées dans la section précédente. 

```cpp
int fact(int n)
{
    //base case
    if ( n == 1)
        return 1;
    else
        return n * n-1 * fact(n-2);
        }
```

Telecharger le projet <a href="{{ site.url }}{{site.baseurl}}part3/factorial.zip"> factorial.zip </a>


## [Memoization](#memoization)
<a name='memoization'></a>


## [Complexity Analysis](#complexity)
<a name='complexity'></a>
