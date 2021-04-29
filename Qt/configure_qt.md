---
layout : page
title  :   Qt Creator et Bibliothèque Stanford
date   :  2021/04/29  
permalink: /qtcreator/
---

Cette page est conçue pour aider à installer puis **configurer** `QTCreator`
avec la bibliothèque **Stanford**.


## Installation QT

###  **1) Download Qt Inline installer**

La page officielle de **QT creator** est dans le site [https://www.qt.io/download-qt-installer](https://www.qt.io/download-qt-installer). 
Visitez ce site, il doit détecter **automatiquement** votre système
d'exploitation et vous offre l'exécutable approprié. Cliquer sur **Download**
pour télécharger le setup `online`.


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/link_qt_creator.png">
</div>


###  **2) Run the installer**

Selon votre système d'exploitation, vous devez lancer l'exécutable qui est la
forme suivante:

- `qt-unified-linux-online-run` pour Linux.
- `qt-unified-windows-version.exe`: pour Windows.
- `qt-unified-macOs-online.dmg`: Pour Mac Os.


Lancer votre installation, qui va vous guider étape par étape. Il faut remarquer
les points suivant dans l'installation.

- Ne considérer pas la version **6** de Qt.
- Choisissez la version la plus élevée qui commence par **Qt.5.xx.0**.
- Vous devez impérativement sélectionner la composante **MinGW8.x.x.32 bit**
  comme illustrée dans la figure suivante:


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/install-windows-mingw.png"
  width="500" height="400">
</div>




### **3) Stanford Library**

Une fois que vous avez terminé cette installation, vous pouvez passer à
l'installation des composantes de la bibliothèques **Stanford** utilisés dans le
cours.

- Télécharger l'archive de cette bibliothèque: <a href="{{ site.url }}{{site.baseurl}}/Qt/CS106.zip"> CS106.zip</a>
- Décompressez cet archive dans un dossier qui porte le nom **CS106**.
 
> Vous devez avoir un dossier nommé **CS106** qui contient deux projets QT.
> - Welcome
> - Library



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/folder_state.PNG">
</div>


### **3.1) Library**

Allez dans le dossier `Library` et ouvrez le fichier `Library.pro` avec
**QtCretaor**.


> Si vous explorer de fichiers ne montre pas les extensions (.pro). Vous pouvez
> changer ceci en allant dans **File->Options, "View" Tab** et puis sous le
> setting **advanced settings** décocher l'option **Hide extensions from known
> file types**.


Accepter les options de configuration de **QT creator**.

<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/configure_project.PNG">
</div>

Vous devez avoir une projet qui contient les sources de la bibliothèque
Stanford.


- Compiler ce projet en cliquant sur la flèche **verte** pour exécuter.


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/configure_and_run.PNG">
</div>


### **4.1) Sample project**

Afin de tester votre installation, rendez vous dans le deuxième dossier
`Welcome` et ouvrez le projet `Welcome.pro`.

1. Compiler le projet.
 > Si vous recez une erreur, c'est que vous avez échoué dans l'étape précédente.

2. Exécuter le projet.

> Vous allez voir un terminal **Qt** qui demande votre nom,



<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/Welcome_console.PNG"
  widht="400" height="300">
</div>

3. Quand vous terminer, la saisie vous devez voir une image comme:


<div class="fig figcenter fighighlight">
  <img src="{{ site.url }}{{ site.baseurl }}/Qt/images/stanford_message.PNG"
  widht="200" height="200">
</div>

