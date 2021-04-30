---
layout : page
title  :  Practical Session on Classe Design
date   :  2021/04/29  
permalink : /bouncingballs/
---


<div class="fighighlight">
<div class=" figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/three-fourths.png" height="200">
</div>

<div class=" figleft">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/vector_image.png" height="200">
</div>
<div class="figright">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/three-fourths.png" height="200">
</div>
</div>


## Talbe de Matière

1. [Fractions](#fractions)
2. [Vector Design](#myvector)
3. [Bouncing Balls](#bouncing)
<a name='linkLabel'></a>




## [Fractions](#fractions)
<a name='fractions'></a>

Dans cet exercice basique, on cherche à developper une classe `Fraction` pour
représenter une fraction mathématique de la forme $$ F = \dfrac{p}{q}$$. Où
$$p$$ est le nominateur et **q** est le dénominateur.


Un diagramme qui résume l'ensemble des fonctionalité de cette classe est
représenté la figure:



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl}}/assignments/05_classes/diagram_fractions.png">
  <div class="figcaption">
   Représentation de la classe <b> Fraction </b>.  
  </div>
</div>

- La classe possède deux **constructeurs**. 
    - Le premier est par défaut.
    - Le deuxième `Fraction(int num, int denom)` reçoit deux arguments pour
      initier les valeurs $$p$$ et $$q$$.

- La classe offre deux getters:
    - `getNum()` et `getDenom()`: pour récupérer les valeurs de $$p$$ et $$q$$
      respéctivement.
    - La fonction `decimal` renvoie le résultat **réel** de cette fraction.

- Vous devez **surchager les opérateurs** suivants:

 1. Opérateur d'addition `operator +`.
 2. Opérateur de multiplication `operator *`.
 3. Opérateur de flux `operator << `.


> Le code de départ est dans <a href="{{ site.url }}{{site.baseurl}}/assignments/05_classes/fractions.zip"> fractions.zip </a>


## [Vector Design](#myvector)
<a name='myvector'></a>

Le but de cet exercice est d'utiliser vos connaissances sur le modèle de
**classes** de `C++` pour implémenter **vous même** un vecteur de **Stanford**
avec toute l'intelligence et les méthodes fournies. Le diagramme de cette classe
est le suivant:

<div class="fig figcenter">
  <img src="{{ site.url }}{{ site.baseurl}}/assignments/05_classes/diagram_vector.png">
</div>


Un projet simple (qui ne contient pas de tests) pour démarer votre
implémentaiton est dans <a href="{{ site.url }}{{site.baseurl}}/assignments/05_classes/vectors.zip"> Vectors.zip </a>



## [Bouncing Balls](#bouncing)
<a name='linkLabel'></a>
