---
layout :  page
title  : Strings
date   :  2021/03/17
permalink: /strings/
---



## Table de matières

1. [C++ Strings et C srings](#cppstrings)
    - [Définition](#definition)
2. [Caractères](#chars)
3. [Méthodes](#methods)
    - [cancatenation - Comparaison](#string_cmp)
4. [Bibliothèque \<ctype\>](#ctype)
5. [Class stringstream](#streams)



## [La classe string](#cppstrings)
<a name='cppstrings'></a>

### [Définition](#definition)
<a name='definition'></a>

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



### [Convertion](#convertion)
<a name='convertion'></a>

La méthode `to_string`  est très utile pour convertir un type de base à un **string**. 


```cpp

#include <iostream>
#include <string>
 
int main() 
{
    double f = 23.43;
    double f2 = 1e-9;
    double f3 = 1e40;
    double f4 = 1e-40;
    double f5 = 123456789;
    std::string f_str = std::to_string(f);
    std::string f_str2 = std::to_string(f2); // Note: returns "0.000000"
    std::string f_str3 = std::to_string(f3); // Note: Does not return "1e+40".
    std::string f_str4 = std::to_string(f4); // Note: returns "0.000000"
    std::string f_str5 = std::to_string(f5);
    std::cout << "std::cout: " << f << '\n'
              << "to_string: " << f_str  << "\n\n"
              << "std::cout: " << f2 << '\n'
              << "to_string: " << f_str2 << "\n\n"
              << "std::cout: " << f3 << '\n'
              << "to_string: " << f_str3 << "\n\n"
              << "std::cout: " << f4 << '\n'
              << "to_string: " << f_str4 << "\n\n"
              << "std::cout: " << f5 << '\n'
              << "to_string: " << f_str5 << '\n';
}

```


si on veut controller le nombre de chiffres après la virgule où le poids de la
chaine, on utilise [`sprintf`](http://www.cplusplus.com/reference/cstdio/sprintf/)

Sa syntaxe générale est:

```cpp
std::sprintf(buffer, "fmt", value);
```

- `fmt`: est le format voulue.
- `value`: est la valeur convertie.
- `buffer`: de type char * ( discuté après) 


Aussi pour la conversion inverse (string-- number), on utilise fonctions
suivantes:

- [stoi](http://www.cplusplus.com/reference/string/stoi/): convertir une chaine
en **entier**.
- [stol](http://www.cplusplus.com/reference/string/stol/): convertir en **long**
- [stof](http://www.cplusplus.com/reference/string/stof/): convertir en
**float**
- [stod](http://www.cplusplus.com/reference/string/stod/): convertir en
**double**.



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
DAWN" en utilisant le code de César par un k = 5.


```cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string message = "ATTACK AT DAWN";
    int key = 5;
    string encoded = "";  //message encodé

    for(auto ch: message)
    {
        //Encoder que les lettres
       if( ch >= 'A' && ch<='Z')        
       {
        //Formule d'encodage
        char  dis= ( ch - 'A' + key) % 26;
        encoded += 'A' + dis;
       }
       else
        encoded += ch;
    }
    cout<<encoded<<endl;
    return 0;
}
```


```shell
Input: ATTACK AT DAWN
Output: FYYFHP FY IFBS
```




## [Méthode de string](#methods)
<a name='methods'></a>
Cette section présente l'essentiel des méthodes utilisées pour la manipulation
des chaines.

### [cancatenation - Comparaison](#string_cmp)
<a name='string_cmp'></a>

- Comme `Java` et `Python`, on peut **concaténer** deux chaine en utilisant
l'opérateur **+** et **+=**.

```cpp
string s1 = "Programmation"
string s2 = s1 + " CPP";  //s2 = Programmation CPP
s1 += " CPP";      //Ajouter CPP à S1
```

- Contrairement à `Java` on peut comparer directement des chaines en utilisant
des opérateurs:

```cpp
string s3 = "Zebra";
if ( s3 == "Tiger" )
    cout<<"Different"<<endl;

if (s3 < "Tiger)
    cout<<"inferieur<<endl;
```

- Contrairement à `Java` et `Python`, les chaines en **C++** sont mutables.

```cpp
s3.append("Giraffe"); // s2 maintenant "ZebraGiraffe"
s3.erase(4,3); // effacer depuis 4, jusquà 7(4+3)
s3[5] = 'i'; // changer un seul caracères
s3[9] = 'e'; //Danger
```

- Contrairement à `Java`, C++ **ne vérifie pas les bornes** quand vous essayer
d'accéder. Ainsi la grande philosophie: 

> Vous devez maitriser ce que vous faites!!!!


- Voici une liste de méthodes utiles de la classe **string**:
    - `s.append(str)`: Ajouter une chaine à la fin.
    - `s.compare(str)`: comme Java, renvoie $$[-1,0,1]$$ selon le résultat de
    comparaison.
    - `s.erase(index, lenght)`: supprime les caractères de longueur *lenght* à
    partir de *index*.
    - `s.find(str)`: Recherche une chaine str, renvoie `npos` en cas d'échec.
    - `s.insert(index, str)`: insert la chaine **str** à la position **index**.
    - `s.size()`: renvoie la longueur de la chaine.
    - `s.substr(start, length)`: renvoie la sous chaine de longueur **lenght**
    qui commence à la position **start**.

## [Bibliothèque Ctype](#ctype)
<a name='ctype'></a>

Une bibliothèque `ctype` offre de fonctions de base pour la vérification des
caractères.


- `#include<ctype>`
- La bibliothèque offre de **prédicats** pour la vérification d'état d'une
caractère. 

    - **isalnum**: vérifie si une caractère est alphanumérique.
    - **isalpha**: vérifie si un caractère est alphabétique.
    - **islower**: si minuscule.
    - **isupper**: majuscule.
    - **isdigit**: chiffre.
    - **isxdigit**: chiffre hexadécimal.
    - **iscntrl**: caractère de contrôle.
    - **isspace**: espace.
    - **tolower**: convertit en minuscule.
    - **toupper**: convertit en majuscule.

- Exemple:

```cpp
string mixed = "ab80c3d27"
cout<<"Chiffres en "<<mixed<<": "<<endl;

for(auto ch: mixed)
    if( isdigit(ch) )
        cout<<ch<<endl;

//Convertir en majuscule
string s = "ma chaine";
for(auto & ch: s)
    ch = toupper(ch)
cout<<"Maintenant "<<s<<endl;
```









## [String Stream](#streams)
<a name='streams'></a>

