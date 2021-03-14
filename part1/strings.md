---
layout :  page
title  : Strings
date   :  2021/03/17
permalink: /strings/
---



## Table de matières

1. [C++ Strings et C srings](#cppstrings)
    - [Définition](#stringdef)
    - [Relation caractères](#stringchar)
    

2. [Caractères](#chars)
3. [Méthodes](#methods)
4. [Bibliothèque \<ctype\>](#ctype)
5. [Class stringstream](#streams)








## [La classe string](#cppstrings)
<a name='cppstrings'></a>

### [Définition](#stringdef)
<a name='stringdef'></a>

En C++, un `string` est une collection de caractères. Pour les utiliser on doit
introduire la bibliothèque `<string>`.


```cpp
#include<string>
...
string s = "hello"
```

- Un **string**  est un groupement de caractères entouré par **" "**.
- On ne peut pas utiliser juste `' '` pour déclarer une chaine en **C++**.
    - `"Ceci est une chaine"`
    - `'Ceci ne lest pas'`
- Au niveau d'**API**, les chaines possèdent la même interface et fonctions que
ceux de **Java** ou **Python**.
- La grande différence par rapport à ces langages est que les chaines de
caractères en **C++** sont `mutables`.
- Une autre différence, est que dans **C++**, on possède deux types de chaines
de caractères.



### [String et caractères](#stringchar)
<a name='stringchar'></a>


## [Tableau de caractères](#chars)
<a name='chars'></a>

Un **string** est construit de caractères de type `char`. Ces caractères peuvent
être obtenus par **indexation** ( Vous devez être assez familiers avec ce
mécanisme).


```cpp
string S = "Fear the Tree"
```


<table align="center">
<thead>
  <tr>
    <th class="tg-0pky">Index</th>
    <th class="tg-0pky">0</th>
    <th class="tg-0pky">1</th>
    <th class="tg-0pky">2</th>
    <th class="tg-0pky">3</th>
    <th class="tg-0pky">4</th>
    <th class="tg-0pky">5</th>
    <th class="tg-0pky">6</th>
    <th class="tg-0pky">7</th>
    <th class="tg-0pky">8</th>
    <th class="tg-0pky">9</th>
    <th class="tg-0pky">10</th>
    <th class="tg-0pky">11</th>
    <th class="tg-0pky">12</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">Character<br></td>
    <td class="tg-btxf">F</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">a</td>
    <td class="tg-0pky">r</td>
    <td class="tg-btxf">' '</td>
    <td class="tg-0pky">t</td>
    <td class="tg-btxf">h</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">' '</td>
    <td class="tg-0pky">t</td>
    <td class="tg-btxf">r</td>
    <td class="tg-0pky">e</td>
    <td class="tg-btxf">e</td>
  </tr>
</tbody>
</table>


Pour accéder à ces caractères, on utilise soit `S[i]` soit la methode `S.at(i)`


```cpp
char ch1 = S[3];  //'r'
char ch2 = S.at(2); //'a'
```

- Remarquer que les caractères sont entourés par `' '` et limité à un seul
caractère.
- La différence entre `[]` et la méthode `.at()` est que l'opérateur `[]` ne
vérifie pas si vous êtes à l'extérieur des limites de votre chaine.

```cpp
char ch1 = S[13];  //erreur de mémoire rien n'est signalé au compilateur
char ch2 = S.at(13);  //Lance une exception out_of_range
```


- A ce stade, vous avez deux méthodes pour parcourir une chaine:

```cpp
//Index based
for(size_t i = 0; i<chaine.size(); i++)
    cout<<chaine[i];
cout<<endl;

//foreach
for(auto ch: chaine)
    cout<<ch;
cout<<endl;
```


- Les *caractères* possèdent aussi un codage `ASCII` comme représenté dans la
figure:

<div class="fig figcener ">
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/ceaser_cypher.png" >

<div class="figcaption"> Le codage de César est une méthode de cryptographie
formée en translatant chaque lettre à droit ou gauche par un paramètre $k$.
Par exemple pour un codage $+3$, la lettre 'A' sera codée par 'D' et 'B' par
'E'. A la fin les lettre devient au début. Par exemple la lettre 'X' sera codée
par 'A', 'Y' par 'B' et 'Z' par 'C'. César a confirmé qu'il as utilisé ce schéma
pour envoyer ces plans d'action de guère pour ces généraux.
</div>
</div>


- Ceci implique qu'on peut réaliser des **opérations mathématiques** sur ces
caractères.

> Exercice: Réaliser un programme un programme qui encode la chaine "ATTACK AT
DAWN" en utilisant le code de César par un k = 3.



## [Méthode de string](#methods)
<a name='methods'></a>



## [Bibliothèque Ctype](#ctype)
<a name='ctype'></a>


## [String Stream](#streams)
<a name='streams'></a>

