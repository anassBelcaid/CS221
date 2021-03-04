---
layout : page
title  : Introducion
date   :  2021-02-28
permalink: /intro/
---


1. [Information du cours](#courseinfo)
 -  [Techniques abstraites](#abstracttechniques)
 - [Apprécier la puissance de récurrence](#recuPower)
 - [Apprendre à analyser des algorithmes](#algoanalys)
2. [Logistique](#logistics)
    - [Portail du cours](#portail)
    - [Plateforme Piazza](#piazza)
    - [Distribution Note Finale](#grade)
    - [Salle d'entrainement](#stepstep)

3. [C++](#cpp)
    - [Définition](#defcpp)
    - [Pourquoi C++](#whycpp)
    - [Compagnies C++](#compagniecpp)
    - [Premier programme](#linkLabel)
    - [Deuxième programme](#secondprogram)
    - [Importance des structures de données](#impdata)




## [**Objectifs**](#objectifs)
<a name='objectifs'></a>


Bienvenue dans le cours **Problem solving with C++**. Comme le nom l'indique
l'objectif de cours est:

> Aquérir des techniques de base pour la **modélisation** et la **résolution**
de **problèmes complexes** avec un ordinateur.


Cependant la notion de problème complèxe evolue avec le temps. Voici une liste
de problèmes:

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/autonomous_driving.png" width="50%" >
  <div class="figcaption"> Exploitation d'imitation de les self driving cars. J.Zhou and al 2021</div>
</div>

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/instantanious_directions.png" width="60%">
  <div class="figcaption"> Calculer le chemin le plus court entre deux points
  étant données informations instantanés.</div>
</div>

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/speech_recognition.png" width="50%">
  <div class="figcaption"> Le problème de reconnaissance de discours.</div>
</div>

## Objectifs du cours
<a name='courseinfo'></a>
> Ce cours ne vas pas vous permettre de coder ces projets. Cepenant c'est une
étape essentielle pour y arriver.


On peut résumer les trois piliers de cours comme:


1. Explorer des **techniques abstraites** pour la résolution de problèmes.
2. Maitriser puis apprécier la puissance de la **récurrence**.
3. Apprendre à analyser et comparer le **compléxité des solutions.**






### [Techniques abstraites](#abstracttechniques)
<a name='abstracttechniques'></a>


1. Comment calculer **distance moyenne** entre deux utilisateurs *facebook*.

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/facebook_distance.png" width="50%">
  <div class="figcaption"> Quelle est la distance moyenne entre deux utilisateurs
  aléatoires en facebook. Les techniques de théorie de graphe sont souvent
  utilisés pour répondre a ce type de question. Ainsi on peut reformuler la
  question en un question classique de <b>théorie de graphe</b>.</div>
</div>


2. Comment peut on envoyer un email d'un ville à une autre.

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/rooting_problem.png" width="50%">
  <div class="figcaption"> Etant donné qu'on veut envoyer un mail d'une certaine
  ville à une autre et une liste de ordinanteurs connectées. Quel est le chemin
  effectif pour délivrer ce mail. La aussi, la modélisation de ce problème en
  forme de <b> graphe </b> réduit le problème la notion de plus court chemin.</div>
</div>


### [Apprécier la puissance de récurrence](#recuPower)
<a name='recuPower'></a>


La récurrence est un paradigme très puissant qui une fois matrisé vous permet de
résoudre un large panorama de problèmes complèxes.

> Si vous voulez comprendre la récurrence, vous devez comprendre la récurence!!!


<div class="fig figleft ">
  <img src="/assets/intro/fractal_tree.jpg" width="40%">
</div>

<div class="fig figright ">
  <img src="/assets/intro/fractal_tree.jpg" width="40%">
  <div class="figcaption"> Image d'un arbre <b>fractal</b>, Si vous zoumer sur une
  partie de cette arbre, vous allez trouver la <b> même image</b></div>
</div>



### [Apprendre à analyser des algorithmes](#algoanalys)
<a name='algoanalys'></a>


L'un des objectifs importants de ce cours est de pouvoir analyser et comparer la
**complexité** des algorithmes proposés. Par exemple visiter [Sorting algorithms playground](https://www.toptal.com/developers/sorting-algorithms)  pour apprécier la différence entre ces algorithmes de tri.


<div class="fig figcenter ">
  <img src="/assets/intro/complexity.png" width="60%">
  <div class="figcaption"> Playground pour explorer la différence entre les
  algorithmes de tri.</b></div>
</div>


## [**Logistique du cours**](#logistics)
<a name='logistics'></a>

### [Portail du cours](#portail)
<a name='portail'></a>


Le portail principal du cours est:
<div class="notyet">
<div class="title-wrap">
<font size = "5">https://anassbelcaid.github.io/CS221</font>
</div>
</div>

Il contient:

1. Planning des séances.
2. Contenu à préparer **avant le cours**.
3. Description des **Travaux pratiques**.
4. Collections de **ressources** pour le cours.




### [Plateforme Piazza](#piazza)
<a name='piazza'></a>

Nous utilisons [**Piazza**](https://piazza.com/) pour le **suivi** des questions
réponses. Voici le lien du cours


<div class="notyet">
<div class="title-wrap">
<font size = "5"> https://piazza.com/class/kloxltowxj642j</font>
</div>
</div>


> Vous devez vous inscrire en utilisant vos mails **académiques** (portant
l'extension euromed.org)


<div class="fig figcenter fighighlight">
  <img src="/assets/intro/piazza.png">
  <div class="figcaption">  Plaforme Piazza pour poser des questions. Votre
  ressource principale pour chercher des réponses.</div>
</div>

Cette plateforme serve comme **portail** de discussion entre vous et aussi pour
poser des questions au professeur.


1. Poser des questions sur chaque notion qui vous bloque.
2. Vous avez le choix de déterminer qui peut voir vos questions:
    - (anonyme) avec le prof ( pas recommandé)
    - (votre nome) mais juste avec le prof (En cas de problème).
    - (Anonyme/non) mais pour toute la classe (**Recommandé**)
3. Vous êtes aussi encouragés a **répondre** aux questions de vos amis dans l'onglet
   réservé aux étudiants.



### [Distribution Note Finale](#grade)
<a name='grade'></a>


le calcul est **à priori** comme suit

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/grades_distribution.png">
  <div class="figcaption">  Distribution de la note finale du module.</div>
</div>


### [Salle d'entrainement](#stepstep)
<a name='stepstep'></a>


je vous recommande le [**Code Step by Step**](https://www.codestepbystep.com)
pour vous entrainner aux notions du cours. D'ailleurs, on va souvement vous
reférer à quelques questions du ce site.

<div class="fig figcenter fighighlight">
  <img src="/assets/intro/code_step_step.png">
  <div class="figcaption">  Votre salle d'enstrainement où vous pouvez vous
  exercez sur différentes notions du cours.</div>
</div>



##  Langage C++
<a name='cpp'></a>


### [Définition](#defcpp)
<a name='defcpp'></a>


Le language [C++](https://en.wikipedia.org/wiki/C%2B%2B) est un language de
programmation **compilé** permettant la programmation avec plusieurs paradigmes
(fonctionnels, OOP ou générique). Ses perfermances de **rapidité** et
compatibilité avec **C** en fontn l'un des languages les plus utilisés des des
applications critiques (gourmandes en calcul) comme les **moteurs de jeu** ou
les framework **deep learning**.



<div class="fig figcenter fighighlight">
  <img src="/assets/intro/lang_popularity.png" width="400px">
  <div class="figcaption"> Worldwide language popolarity comparison: Mar 2021 compared to a year ago</div>
</div>


Voici une liste de cours qui utilisent **C++** comme leurs langage de base.


1. Physics Based simulation Biological Structure.
2. **[Introduction to Cuda](https://ericdarve.github.io/)** (**Deep learning**). 
3. [**Introduction to Computer Networks**](http://web.stanford.edu/class/cs244a/)
4. [**Convolutional Neural Networks**](https://medium.com/syntechx/convolutional-neural-network-cnn-in-c-52c9ed47a6ea)
5. Parallel computing in **Healthcare**. 
6. Medical **Robotics**.
7. **Music computing** design.
8. **Signal processing** models.


#### [Pourquoi C++](#whycpp)
<a name='whycpp'></a>

Etant donné l'explosion et l'efficacité des réseaux de neurones. Tous les
**framework** en base sont implémentés en `C++` pour leur efficacité. Puis
offrent des interfaces en des langages simples comme `Python` pour leur
exploitation.


```cpp
/*
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <vector>

#include "tensorflow/cc/framework/grad_op_registry.h"
#include "tensorflow/cc/framework/gradients.h"
#include "tensorflow/cc/ops/array_ops_internal.h"
#include "tensorflow/cc/ops/standard_ops.h"
#include "tensorflow/core/lib/strings/strcat.h"

namespace tensorflow {

REGISTER_NO_GRADIENT_OP("ShapeN");
REGISTER_NO_GRADIENT_OP("Rank");
REGISTER_NO_GRADIENT_OP("Size");

Status UnpackGrad(const Scope& scope, const Operation& op,
                  const std::vector<Output>& grad_inputs,
                  std::vector<Output>* grad_outputs) {
  int axis;
  TF_RETURN_IF_ERROR(GetNodeAttr(op.node()->attrs(), "axis", &axis));
  grad_outputs->push_back(Stack(scope, grad_inputs, Stack::Axis(axis)));
  return scope.status();
}
```

<div class="figcaption"> Code C++ de Array grad sur tensorflow.</div>


### [Compagnies C++](#compagniecpp)
<a name='compagniecpp'></a>

**Les compagnies qui utilisent C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/amazon.png" width="24%" height="80">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/intel.png" width="80" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/facebook.png" width="80" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/google.png" width="100" height="80">      
  <br>
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/apple.png" width="100" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/microsoft.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/adobe.png" width="24%" height="80">      
<div class="figcaption"> Ensemble des compagnies qui utilisent C++ dans le
développement de leur code.</div>
</div>



**Quelques logiciels écrits en C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/java.png" width="150" height="60">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/office.jpg" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/photoshop.png" width="150" height="60">      
  <br>
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/vlc.png" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/windows.jpg" width="150" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/youtube.png" width="150" height="60">      
<div class="figcaption"> Quelque logiciels écrit en C++</div>
</div>


**Projets écrit en C++**

<div class="fig figleft">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/project_1.png"
width="40%" height="200">
</div>
<div class="fig figright">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/project_2.png"
width="40%" height="200">
</div>

<div class="figcaption"> Projets réalisés en C++. A gauche, le <b>F35</b> Lightning
|| qui qui se base principalement sur C++. A droite, le <em>Spirit rover</em> qui était
opérationnel pour 6 années alors qu'on planifier juste une mission de trois
mois.</div>


> Pourqu'oi doit ont choisir C++

<div class="fig figleft">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/c++_timing.png"
width="40%" height="230">
</div>

<div class="fig figright">
<img src="{{ site.url }}{{ site.baseurl }}/assets/intro/c++_lowlevel.png"
width="40%" height="200">

</div>
<div class="figcaption"> Diagramme illustrant la <b>rapidité</b> de C++ comparé
aux autres langages de programmation dans les deux platformes linux et windows. Aussi C++ offre un contrôle bas niveau pour un contrôle rafiné des ressources du programe.</div>



### [Premier programme](#linkLabel)
<a name='linkLabel'></a>

Pour avoir une iddée sur la syntaxe de **cpp** qui resssemble aimplement à celle
de **Java**, On se propose de résoudre le problème d'affichier les **trois**
premiers nombres `parfaits`.

> Un nombre est parfait s'il est égal à la somme de tous ces diviseurs sauf lui
même.

Par exemple le nombre $$6$$ est parfait car 

$$

6 = 1 + 2 + 3
$$


```cpp
#include <iostream>  

//utiliser l'espace des nom std
using namespace std;

//Fonction pour vérifier si n est pafait
bool is_perfect( int n)
{
    auto S = 0;

    for(auto div=1; div <= n/2; div++)
        if ( n % div == 0)
            S += div;

    return S == n;
}

//fonction principale
int main(int argc, char *argv[])
{

    int count = 0;  //count des nombres parfaits

    int candidate = 1; //nombre à vérifier

    while( count < 3)
         {
             if(is_perfect( candidate ))
                {
                   cout<<candidate<<" ";                
                     count++;
                }
             candidate++;
         }
    //Retour à la ligne
    cout<<endl; 
    
    return 0;
}
```


### [Deuxième programme](#secondprogram)
<a name='secondprogram'></a>

```cpp
/*tracer une distribution normale
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
 
int main()
{
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()}; 
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
 
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

```


### [Importance des structures de données](#impdata)
<a name='impdata'></a>

La maitrise des **structure de données** est un atout **indispensable** à
n'importe quel programmeur sérieux. Savoir utiliser la structure de donnée
`adéquate` peut réduire le temps l'éfficacité de programme par des facteurs de
centaines.

<div class="fig figleft ">
  <img src="/assets/intro/arrays.png" width="30%" >
</div>
<div class="fig figleft ">
  <img src="/assets/intro/linked_list.png" width="30%" >
</div>
<div class="fig figleft ">
  <img src="/assets/intro/trees.png" width="30%" >
</div>

<div class="figcaption"> Ensembe des structures de données basiques pour la résolution de problème. A gauche, vous trouvez votre structure de base qui est un <b>tableau</b>. Cette structure est dite linéaire puisque elle offe un accès simple à ces composantes. La deuxième est une <b>Liste chainée </b> qui est aussi linéaire mais dont les éléments ne sont pas contigues dans la mémoire. Finalement à droite on trouve un <b> arbe </b> qui est une structure basique pour représenter la connectivité entre éléments.</div>


> Supposons qu'on veut écrire un programme qui collection.
> 1. Ajouter $$10^6$$ éléments a cette collection.
> 2. Exécuter $$10^6$$ recherche dans cette collection pour confirmer
     l'éxistence d'un élément.
> 3. Essayer de supprimer $$10^6$$ de cette collection.


Voici les résultats de cette expérience sur un ordinateur `2.8GHz Intel Core i7`
en utilisant différents structure de données.


<center>
<style type="text/css">
.tg  {border-collapse:collapse;border-color:#ccc;border-spacing:0;}
.tg td{background-color:#fff;border-color:#ccc;border-style:solid;border-width:0px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{background-color:#f0f0f0;border-color:#ccc;border-style:solid;border-width:0px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-c3ow{border-color:inherit;text-align:center;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-c3ow">Structure</th>
    <th class="tg-c3ow">Temps total<br></th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-c3ow">Vecteur</td>
    <td class="tg-c3ow">15.057</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Vecteur Trie</td>
    <td class="tg-c3ow">1.563</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Liste chainée</td>
    <td class="tg-c3ow">92.202</td>
  </tr>
  <tr>
    <td class="tg-c3ow">HashTable</td>
    <td class="tg-c3ow">0.145</td>
  </tr>
  <tr>
    <td class="tg-c3ow">Arbre binaire</td>
    <td class="tg-c3ow">0.164</td>
  </tr>
</tbody>
</table>
Temps d'exécution pour chaque structure.
</center>


On remarque que la structure `hashmap` est parfaitement adaptée pour cette
tâche. Cependant on va voir qu'll offre son **comprimis**. Par rapport à
l'utilisation d'un **vecteur simple** on as une accélération de $$103$$x. Et
par rapport à **liste chainée** on a une réduction de $$\mathbf{636}$$x.


