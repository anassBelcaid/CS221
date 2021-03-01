---
layout :  page
title  :  Welcome to CS221
date   :  2021-03-10
permalink: /debugging/
---

1. [Objectifs](#goals)
2. [Installation QT](#installQt) 
3. [Tutorial deboggage](#debug)

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

- <a href="{{site.baseurl}}/assets/code/ass/HW0_NameHash.zip"> Code de Départ</a>







