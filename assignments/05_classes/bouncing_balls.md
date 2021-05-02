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
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/bouncing_logo.png" width="300" height="200">
</div>
</div>


## Talbe de Matière

1. [Fractions](#fractions)
2. [Vector Design](#myvector)
3. [Bouncing Balls](#bouncing)
    - [Graphical Window](#graphic)
    - [Adding Objects](#objects)
    - [Moving Objects](#moving)
    - [Final  result](#moving)




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
<a name='bouncing'></a>

Dans cet exercice, vous allez être exposés aux fonctionnement **graphiques** de
la bibliothèque **Stanford**. Votre tache consiste à initialiser une fenêtre
graphique et de d'y ajouter des **balles** qui se déplace librement dans celle
ci.

> Le code de départ de ce projet est dans <a href="{{ site.url }}{{site.baseurl}}/assignments/05_classes/bouncingBall.zip"> Bouncing_balls.zip </a>


Ces notes vont vous aider à démarrer le projet en vous montrant comment:

1. Créer une fenêtre graphique qui peut contenir des objet.
2. Ajouter un objet `GOval` qui peut représenter une **balle**.
3. Comment **déplacer** ces objets dans la fenêtre.


> Pour le reste c'est  **à vous de concevoir** votre modèle de classes et de
> l'implémenter pour obtenir la simulation illustrée.



### [Graphical Window](#graphic)
<a name='graphic'></a>

Afin de construire une fenêtre graphique, on utilise un objet de la classe
`GWindow` qui figure dans le header `gwindow.h`.


- Allez dans le fichier `main.cpp` puis ajouter la ligne suivante:

```cpp
// Créer une fenêtre de taille 600, 600
Gwindow win(600, 600);

// Fermer l'application avec la fermeture de cette fenêtre.
win.setCloseOperation(GWindow::CLOSE_EXIT);
```

- Vous devoir une fenêtre vide, qui occupe une taille de $$600 \times 600$$.

<div class=" figcenter ">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/simple_app.PNG" width="400" height="300">
</div>


- Pour obtenir la taille de cette fenêtre, on peut utiliser les deux accesseurs:

```cpp
// Obtenir la largeur
wind.getWidth();

//Obtenir la longueur
wind.getHeight();
```

Maintenant qu'on possède une fenêtre graphique, on peut la remplir par des
objets graphiques comme un **cercle**.


###  [Adding Objects](#objects)
<a name='objects'> </a>

La bibliothèque **Stanford** offre plusieurs objet graphiques qui peut être
tracés dans une fenêtre `GWindow`. Les objet qu'il faut retenir sont:


1. `GLine(x0, y0, x1, y1)`:  pour tracer une ligne entre $$A(x_0, y_0)$$ et
   $$B(x_1, y_1)$$.

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/Line.png" 
  height="200" width="300">
</div>


2. `GOval(x, y, r1, r2)`: pour tracer un **ellipse** de centre $$C(x,y)$$ et
   deux rayons $$r_1$$ et $$r_2$$.


<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/Oval.png"
  height="200" width="300">
</div>
3. `GRect(x, y, l, h)`: pour tracer un **rectangle** dont le corner 

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/Rect.png"
  height="200" width="300">
</div>


Ainsi afin d'ajouter un **cercle** qui va représenter une boule  ajouter le code
suivant:


```cpp
//Creating a ball
GOval * oval = new GOval(300, 300, 40, 40);

//set Color
oval->setFillColor(45133);
oval->setFilled(true);

//Add the ball to the window
win.add(oval);
```

Vous devoir voir apparaitre une boule

<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/simple_ball.PNG" height="200" width="300">
</div>

###  [Moving Objects](#moving)
<a name='moving'></a>


Maintenant qu'on peut ajouter des balles dans l'écran, nous allons essayer des
les déplacer. L'objet `GOval` possède une méthode **move**.

```cpp
oval->move(dx, dy); // Déplacer par dx et dy
```

> Le problème est que cette méthode ** ne vérifie pas** si l'objet sort des
dimensions de la fenêtre. 


Votre tâche est de coder le bon déroulement de cette ball pour qui'elle puisse
bondir au moment de son contact avec un bord comme illustré la figure suivante.

<div class=" figcenter ">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/bouncing_diagram.png">
</div>



### [Final result](#final)
<a name='final'> </a>

Le résultat final de votre simulation doit avoir plusieurs **balls** qui se
déplacent librement ( sans collision) dans votre boite.


<div class="figcenter">
  <img src="{{ site.url }}{{ site.baseurl }}/assignments/05_classes/bouncing_balls.gif" height="200" width="400">
</div>


