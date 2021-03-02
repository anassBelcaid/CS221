---
layout :  page
title  :  Welcome to CS221
date   :  2021-03-10
permalink: /debugging/
---

1. [Objectifs](#goals)
2. [Installation QT](#installQt) 
3. [Tutorial deboggage](#debug)
4. [Exercice: Débogage Tri à bulles](#bublesort)

## [Objectifs](#goals)
<a name='goals'></a>

Bienvenue à cette première séance de **Travaux pratiques**. Le but est de:

- Installer et configurer votre **environnement intégré** [QT creator](https://www.qt.io/product/development-tools)
- Attacher des bibliothèques externes, comme [stanford C++](https://www.url.com).
- Se familiariser  les fonctionnalités de **[debuging](https://en.wikipedia.org/wiki/Debugging)**.
- Utiliser ces techniques pour fixer des erreurs dans le **[Tri par bulles](https://en.wikipedia.org/wiki/Bubble_sort)**.


## [Installation QT Creator](#installQt)
<a name='installQt'></a>


Votre première tache consiste à installer et configurer **QtCrator**. C'est un
*Environnement de développement intégré (IDE)* qui vous assiste dans toute les
étapes ( écriture, compilation, débogage).


Suivez les instructions dans le [guide d'installation](https://doc.qt.io/qt-5/gettingstarted.html) en
choisissant votre système d'exploitation.


Si vous voulez **tester** votre configuration:

1. Lancer **QtCreator**.
2. Créer un nouveau projet.
3. Spécifier `Non Qt project`
4. Pour la configuration choisissez `cmake`
5. Si vous utiliser `git`, vous pouvez le choisir pour gérer les versions de
   votre programme.

6. Construire votre programme.
7. Lire et comprendre le contenu du fichier de configuration `CMakeLists.txt`



## [Tutorial deboggage](#debug)
<a name='debug'></a>

Nous allons utiliser un simple projet utilisant la bibliothèque de **Stanford**.
Ainsi, vous devez télécharger le code de début. Décomprésser le puis ouvrez le fichier **NameHash.pro** qui contient la configuration du projet.

- <a href="{{ site.url }}{{site.baseurl}}/assets/code/ass/HW0_NameHash.zip"> Code de Départ</a>


1. Ouvir le project `NameHash.pro`.
2. Exécuter le projet et saisissez vos informations.
3. Maintenant on veut suivre et comprendre l'exécution de de code. 
    - Chercher la ligne **66** dans le fichier `name_hash.cpp`
    - Cette ligne contient le code suivant `ch = tolower(ch)`
    - Ajouter un **breakpoint** dans cette ligne.
    - Lancer maintenant le programme mais avec le mode **débogage**.
4. Vous remarquez la flèche jaune qui indique l'état actuel de l'exécution.


 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_arrow.png" width="80%" class="figcenter">


> Apprenez a suivre toujours cette flèche, pour connaitre l'emplacement ou l'état
d'exécution de votre programme.


Maintenant, on se concentre sur le panneau en bas. Il s'appelle `Pile
d'exécution`.


 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_call_stack.png" width="80%" class="figcenter">

 Ce panneau, vous montre les **appels** régis par la fonction **main**.

 A partir de ce panneau, on peut remarquer qu'on est dans la fonction `nameHash`
 qui est était appelée dans la fonction `main`.


> Essayer de cliquer sur la fonction `main`, vous allez observer que vous allez
être déplacer automatiquement dans la fonction main. 

> Très très utile pour suivre les sources d'appels et ainsi découvrir la source
d'erreur.


A ce stade on connait où on est dans le programme, La hiérarchie des fonctions
appelées. Mais qu'en est il des valeurs des variables?

On peut voir une liste des variables locales ainsi que leur valeur dans le
panneau à droite.

 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_var_state.png" width="80%"  height="200px" class="figcenter">

 Ce panneau vous montre les variables en utilisation, leur **types** et leurs
 valeurs. Par exemple on peut constater qu'on as accès à une variable `ch` de
 type **char** et qui possède la valeur `B`.


> Quel est le type et la valeur de la variable `hashVal`?

Dans la suite on va exécuter le programme étape par étape et voir l'évolution de
ces variables an action.

Commençons notre investigation de la boucle for


```cpp
for (char ch: first + last) {
        /* Convert the input character to lower case. The numeric values of
         * lower-case letters are always less than 127.
         */
        ch = tolower(ch);
        hashVal = (kSmallPrime * hashVal + ch) % kLargePrime;
    }
```

Cette boucle va itérer les **caractères** de mon nom complet. La première
lettre est `B`. 

Exécutons, maintenant la ligne `tolower(ch)` qui change une lettre en
**minuscule**. Pour ce faire on doit maitriser les actions suivantes:


 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_action_buttons.png" width="50%"  height="50px" align="center">

Mettre la sourie sur chaqune pour connaitre leurs noms.

. **Step over**: Progresser d'une ligne dans le programme. Cliquer sur cette
icone et vous allez observer qu'on vient d'exécuter la ligne `tolower(ch)` et
que maintenant la variable `ch=b` dans la zone des variables.

 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_var_change.png" width="80%"  height="200px" align="center">

 > Observer la flèche **jaune** pour identifier votre emplacement.

 Passons maintenant à la ligne suivante qui calcule une valeur de `hashage` pour
 note caractère.


```cpp
hashVal = (kSmallPrime * hashVal + ch) % kLargePrime;
```

Exécutons une autre fois le bouton `step over` pour voir l'effet de cette ligne.

 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_hash_upd.png" width="80%"  height="150px" align="center">

 Une fois encore, on obtient la valeur calculée pour notre caractère **b**.

 > Continuer à avancer jusqu'à vous sentez que vous avez bien maitrisé la
 fonction **nameHash**.


. **Step out**: Avancer l'éxécution juste par des simples linges, sera trop
**fastidieux**, si notre programme se compose d'une longue boucle comme le cas
ici. Pour se faire on peut exécuter le code jusqu'à la **fin d'une fonction**
par le bouton `step out`.

1. Cliquer sur ce bouton, puis observer votre espace des variables.
2. Vous devez remarquer que toutes les variables **locales** associées à la
   fonction `nameHash` sont disparus.

 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_step_out.png" width="50%"  height="80px" align="center">

 1. Observer la valeur finale du `hashValue`
 2. Identifier l'emplacement de la flèche jaune qui indique notre **retour** à
    la fonction `main`.

> Observer aussi, qu'à ce stade on possède aussi la valeur de retour de la
fonction 


 <img src="{{ site.url }}{{ site.baseurl }}/assets/debugging/deb_return_value.png" width="50%"  height="60px" align="center">

 Chose intéressante,car on peut voir l'état de la fonction avant
 l'**affectation**. Exécuter votre final **Step over**, pour réaliser cette
 affection puis observer votre variable `hashValue`.



## [Exercice: Débogage Tri à bulles](#bublesort)
<a name='bublesort'></a>


Pour tester vos connaissance en **débogage** télécharger le project:

- <a href="{{ site.url }}{{ site.baseurl }}/assets/code/ass/debuging_exo.zip">Tri à bulles </a>


1. Télécharger puis décompresser le fichier `debuging_exo.zip`.
2. Ouvre le projet avec **QtCretaor**.
3. Exécute votre code ( vous aurez une erreure de **mémoire**)
4. Utiliser vos nouvelles techniques pour identifier ces **bugs**.


