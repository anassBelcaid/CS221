---
layout : page
title  : Introducion
date   :  2021-02-28
permalink: /intro/
---


1. [Information du cours](#courseinfo)
2. [Objectifs du cours](#objectifs)
3. [Logistique](#logistics)
4. [C++](#cpp)



<a name='objectifs'></a>
<a name='courseinfo'></a>
<a name='logistics'></a>





##  Langage C++
<a name='cpp'></a>


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
namespace ops {
namespace {

REGISTER_NO_GRADIENT_OP("Const");
REGISTER_NO_GRADIENT_OP("StopGradient");
REGISTER_NO_GRADIENT_OP("ConcatOffset");
REGISTER_NO_GRADIENT_OP("EditDistance");
REGISTER_NO_GRADIENT_OP("ZerosLike");
REGISTER_NO_GRADIENT_OP("InvertPermutation");
REGISTER_NO_GRADIENT_OP("Shape");
REGISTER_NO_GRADIENT_OP("ShapeN");
REGISTER_NO_GRADIENT_OP("Rank");
REGISTER_NO_GRADIENT_OP("Size");
REGISTER_NO_GRADIENT_OP("BroadcastGradientArgs");
REGISTER_NO_GRADIENT_OP("OneHot");

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


**Les compagnies qui utilisent C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/amazon.png" width="24%" height="80">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/intel.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/facebook.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/google.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/apple.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/microsoft.png" width="24%" height="80">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/adobe.png" width="24%" height="80">      
<div class="figcaption"> Ensemble des compagnies qui utilisent C++ dans le
développement de leur code.</div>
</div>



**Quelques logiciels écrit en C++**


<div class="fig figcenter fighighlight">
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/java.png" width="33%" height="60">      
    <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/office.jpg" width="33%" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/photoshop.png" width="33%" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/vlc.png" width="33%" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/windows.jpg" width="33%" height="60">      
  <img src="{{ site.url }}{{ site.baseurl }}/assets/intro/youtube.png" width="33%" height="60">      
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


> Pourqu'oi dont ont choisir C++

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


