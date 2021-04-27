---
layout :  page
title  :  Designing Classes  
date   :  2021/04/23  
permalink: /classes/
---



<div class="figcenter">
<img src="{{ site.url }}{{ site.baseurl }}/part3/images/colorful-boxes.png"
width="400" height="300">
</div>


## Table de Matière

1. [C++ Classes](#cppclasses)
    - [Pouqu'oi OOP](#whyoop)
    - [Elements d'une classe](#classelem)
    - [Constructeur](#construct)
    - [Structure d'une classe](#classtruct)
    - [Encapsulation](#encapsul)

2. [Classes et pointeurs](#class_point)
   - [Objet pointeur](#objectPointer)
   - [Pointeur Implicit (this)](#this)
   
3. [Operator Overloading](#overloading)
    - [Unary operators](#unary)
    - [Binary operators](#binary)
    
4. [Templats](#templates)
<a name='templates'></a>


   
    


## [Les Classe C++](#cppclasses)
<a name='cppclasses'></a>


### [Pouqu'oi OOP](#whyoop)
<a name='whyoop'></a>

La programmation **Orienté objecté** offrent plusieurs avantages comparés à
celle de l'approche **fonctionnelle**.

- Décapsulation des données.
- Héritage.
- Polymorphisme.
- Modularité et sécurité des données.


Afin d'illustrer ces deux approches, on va considérer un code `haut niveau` pour
le traitement des images.

Une image ( en grille) est caractérisée par son nombre de lignes (`height`) and
colonnes (`width`). Chaque pixel de cette image est une valeur qui représente le
niveau de gris.


<div class="fighightlight figcenter">
<img src="{{ site.url }}{{ site.baseurl }}/part3/images/image_as_matrix.png" width="500">
<div class="figcaption">
Illustration de la représentation d'une image en niveau de grille par une matrice (<b>Grid</b>)
d'entiers.
</div>
</div>

#### Approche procédurale.

```cpp
void load_image(string &filename, vector<int> & data, int & rows, int & cols)
{
    ....
}

void save_image(string &filename, vector<int> & data, int & rows, int & cols)
{
    ...
}

bool isEmpty(vector<int> & data, int rows, int cols)
{
    if( data.size() == 0 ) 
        return true;
}
```

Si on veut utiliser ces fonctions, voici un aperçu d'une simple fonction main

```cpp
int main()
{
    //Data of the image
    vector<int>  data;
    int rows;
    intn cols;

    //loading the image
    load_image("Lena.png", data, rows, cols);

    //checking if the data
    if (! isEmpty(data, rows, cols) ) 
    {
        //do something
    }

    //Saving the new image
    save_image("new_image.png", data, rows, cols);
}
```


#### Approche OOP:

Le code listé représente plusieurs erreurs de représentation surtout pour un
langage comme `c++`. On peut mentionner les problèmes suivants:


- A chaque fois qu'on veut se référer à une image, on doit mentionner les trois
  données:
    - `data`, `rows` et `cols`.

- On peut facilement se tromper dans le passage d'arguments.

- Aucune sécurité dans les données, on peut facilement remplacer le vecteur
  `data` et passer pour une autre image.


Comparons maintenant à une nouvelle approche qui utilise l'approche `OOP`.


```cpp 
class Image{
    //private data
    private:
        vector<int> data_;
        int rows;
        int cols;

    //Public part
    public:
        Image();  //Constructor
        Image(string &filename);
        ~Image();       //Destructor

        //methods
        void save(string &filename);
        bool empty();
};
```



La fonction `main` devient plus simple:


```cpp
int main()
{
    //Creating Image
    Image lena("lena.png");

    //do something
    if ( lena.empty() )
    {
        ....
    }

    //Saving the image
    lena.save("new_lena.png");
}
```




### [Elements of a class](#classelem)
 <a name='classelem'></a>

- Une classe est utilisée pour **encapsuler** des données avec un ensemble de
  **méthodes** pour leur traitements.
- Une classe définit un nouveau **type** de donnée. Voici la structure générale
  d'une classe en *C++*.

```cpp
class NewType {

    //Constructor Desctuteurs
public:
    NewType();
    ~NewType(); 

    // Member functions
public:
    void MemberFunction1();
    void MemberFunctions2() const;
    static void StaticFunction();

    //Operators
public:
    NewType &operator+=(const NewType & other);
    friend ostream &operator<<(ostream &os, const NewType &obj);

    //Private data
private:
    int a_;
    vector<float> data_;
    OtherType member_;
};
```

Ainsi on peut lister les éléments d'une classe comme suit:

- `Attributs` : Définit l'état d'un objet.
    -  Appelés aussi *member variables*.
    -  Doivent être privés à l'objet.
    - Chaque objet possède sa propre **copie**.

- `Méthodes`: Ensemble de fonctions ou comportement d'un objet.
    - Appelés aussi `member functions`.
    - Chaque objet crée possède sa propre **copie**.
    - Ces méthodes peuvent accéder directement aux attributs.

- `Constructor/Destructor`: Fonction spéciales pour initialiser et détruire les objets.
    - Création et initialisation des attributs.
    - Destruction de ressources prises par un objet (Mémoire, fichier, ...)

- `Operateurs`:  Partie pour **surchager** les opérateurs de base.

    - Souvent utilisés définir les opérateur de bases comme +.
    - Amplement encouragés puisque ils facilitent la conception du code.


### [Constructeurs](#construct)
<a name='consruct'></a>

Les **constructeurs** méritent une discussion détaillée en **c++**.


1. Une classe doit posséder **au moins** un constructeur.
2. Une classe possède **un unique** destructeur.
3. **Constructeurs**:
    - Des fonctions qui ne possèdent pas de valeurs de retour.
    - Possède le **même nom** que la classe.
    - On peut définir **plusieurs** constructeurs.
    - Si on définit aucun constructeur, **C++** génère un par **défaut**.
4. **Destructeur**:
    - Fonction  qui porte le nom `~ClassName`.
    - Appelé automatiquement lorsque un objet est détruit.
    - Aussi généré explicitement par **c++** si aucun destructeur n'est définit.

```cpp
class SomeClass
{
public:
    SomeClass ();           //Default constuctor

    SomeClass(int a);                 //Custom constructor

    SomeClass(int a, float b);       //With two values

    ~SomeClass ();           //Destructor

};

int main(int argc, char *argv[])
{
  SomeClass var_1;            //Call default

  SomeClass var_2(2);          //Second constructor
  
  SomeClass var_3(1, 4.2);          //third constructror

  //Also recommended unifrom initializer
  SomeClass var_4{};
  SomeClass var_5 = {10, 10.0};

  return 0;
}
```

### [Structure d'une classe](#classtruct)
 <a name='classtruct'></a>

Quand on veut construire une classe en **c++**, on fournit une `interface` à
l'utilisateur qui décrit les détails de celle ci. L'utilisateur n'as pas besoin
d'accéder à l'**implémentation** de ces méthodes.

- L'**interface** d'une classe est mise dans un header. e.g `class_name.h`.
- Le client accède à cet entête  pour obtenir les déclarations des méthodes.

- Le fichier source est réservé dans un fichier `class_name.cpp`.
- Ces fichiers ne sont pas partagés avec l'utilisateur.
- Ils sont délivrés à l'utilisateur dans une forme **compilée**.


#### Structure d'un fichier entête.

```cpp
#pragma once

class className {
public:

    ClassName();  // constructor
    returnType func1(paremeters); //member functions
    returnType func2(parameters); 
    returnType func3(paremters); 

private:

    type var1; //member variables
    type var2;
};
```


- `pragma once`: assure que ce fichier est inclut qu'une **seule fois**.

- Le client peut utiliser tous les méthodes par:

```cpp
MyClass a;

a.func1(arguments);
```


- Le client par contre ne peut pas accéder aux données privées.

```cpp
MyClass a; 
a.var1 = 2;      //Génère une erreur
```

Pour les différents modes d'accès à une variable, on possède:


- `public`: Accessible par tout dans un programme.
- `protected`: Accessible seulement à l'intérieur de la classes et ceux qui
  **héritent** de celle ci.
- `private`: Accessible uniquement à l'intérieur de la classe.
    
##  [Classes and pointers](#class_point)
<a name='class_point'></a>


### [Objet pointeur](#objectPointer)
<a name='objectPointer'></a>

Dans cette section, nous discutons la relation qui existe entre les classes (
structures) et les **pointeurs**. Les facteurs qui changes sont:

1. L'opérateur d'accès aux membre et aux `fonctions`.
2. Gestion de mémoire avec l'opérateur `new`.


- On suppose qu'on dispose d'un classe `Point` avec deux attributs qui sont
l'abscisse et l'ordonnée.
- Cette classe Possède deux constructeurs:
    - Un constructeur par **défaut**.
    - Un constructeur par deux arguments.

- Une méthode `move` pour déplacer cet objet.
- Une fonction `Print` pour afficher le point.


```cpp
class Point
{
public:
  Point();
  Point(float x, float y);
  ~Point();


  void move(float dx, float dy);
private:
    float x;
    float y;
}
```

Supposons maintenant qu'on cherche a manipuler un **Point** par un pointeur.

1. Dans un premier exemple, on suppose que le Point est crée normalement.
   Remarquer l'utilisation de l'opérateur `->` au lieur de `.` pour accéder
   aux attributs et méthodes.

```cpp
Point A;       //Default constructor
Point B(2., 3.4);  //Classical constructor

//Creating a pointer of type Point
Point* P = nullptr;

//Pointing on A;
P = &A;
cout<<"P point on A in: "<<endl;
P->Print();

//Manipulating A with P ( -> )
cout<<"Moving P by (2, 1)"<<endl;
P->move(2, 1);

//Print A state
cout<<"Now A is on : "<<endl;
P->Print();

//changing P adress
P = &B;
cout<<"Now P point on B"<<endl;
B.Print();

//Moving
cout<<"Moving B by (-1,1)"<<endl;
P->move(-1,1);
P->Print();
```


2. Dans le deuxième exemple, on va créer nous même le **Point** avec l'opérateur
   `new`.

```cpp
cout<<"Creating a new empty point"<<endl;
P = new Point;  // Calling new on on default argument
P->Print();
delete P;

//Pointer with no default
cout<<"Creating a Point on position (4, 5)"<<endl;
P  = new Point(4, 5);  //New with classical
P->Print();
delete P;

//Creating an array of pointers
Point * arr = new Point[5]; 

//Printing the content of the arry
for( P = arr; P - arr < 5; P++)
{
  P->Print(); 
  cout<<" ";
}
cout<<endl;

delete [] arr;
```





### [Pointeur Implicit (this)](#this)
<a name='this'></a>

Comme vous avez appris en `Java`, on peut utiliser l'argument **implicite** dans
chaque méthode.  Cette variable se réfère à **l'objet courant**. 

> En java la variable this est un **pointeur**.


Voici un exemple qui utilise cette variable pour initier les instances de la
classe **Point**.

```cpp
Point( float x, float y)
{
    //Utilisation this pour faire la différence avec celle x (argument)
    this->x = x;
    this->y = y

}
```



## [Operator Overloading](#overloading)
<a name='overloading'></a>

En **C++**, on peut implémenter différents `opérateurs` pour les types définies
par l'utilisateur. Ceci est connu par [**Operator Ovearlong**](https://en.cppreference.com/w/cpp/language/operators)


Prenons par exemple la classe `Point`, pour afficher un point, on est étais
toujours ramener à appeler cette fonction pour

- **afficher** un point.
- **Ajouter** un autre point.

```cpp
Point A;
Point B(3, 4);

A.Print();  //Afficher

A.add(B);   //Ajouter B
```

Une manière plus simple et qui est encouragée dans la philosophie de **C++** est
de surcharger les opérateurs de base pour réaliser ces opérations. 

Imaginons qu'on puisse écrire:

```cpp
Point A;
Point B(3, 4);

cout<< A ;  //Afficher

A += B;   //Ajouter B
```


Ceci est réalisable en définissant des méthodes spéciales qui possède le mot
`operator`.

On définit cette méthode à l'intérieur de la classe avec la syntaxe suivante:


```cpp
class clasName {
    ... ... ...

    public:

        returnType operator symbol (arguments) {
            ...
        }
};
```

- **returnType**: est le type de retour de cet opérateur.
- **symbol** : est le symbole qui représente cet opérateur. Comme `+`, `<` `++`.
- **arguments**: La listes des arguments pour cette fonction.


> Pour des opérateurs, on remarque deux classes, ceux qui sont **unaires**
> (utilise un seul élément comme ++), ou **binaire** (utilisant deux élément
> comme +).


### [Unary operators](#unary)
<a name='unary'></a>
Les opérateurs **unaires** s'appliquent à une seule **instance** de la classe.
Exemples de ces opérateurs sont:

- `++`, `--`: L'opérateur d'incrémentation et décrementation.
- `+=`:  Incrémentation avec une valeur.
- `<<`: Flux de sortie.

Pour illustrer ce concept, nous allons considérer l'exemple d'une classe simple `counter` qui
stocke le nombre d'itération d'un programme. 

```cpp 
// Class definition
class Counter {
public:
  Counter() : count_(0){};

  // opeartors
public:
  void operator++ ()  //Prefix increment (++var)
  {
      count_ ++;
  }
  
  void operator++ (int)  //Postfix incrment (var ++)
  {
      count_ += 2;
  }

  void operator+=(int value)  //increment with value +=
  {
      count_ += value;
}


private:
  int count_;


//Friends
friend ostream & operator<<(ostream&, const Counter &);
};


ostream & operator<<(ostream & out, const Counter & C)
{
    out<< "Counter("<< C.count_<< ")";


    return out;
}
```

Remarquer la différence entre les deux [opérateurs d'incrémentation](https://en.cppreference.com/w/cpp/language/operator_incdec). 

- L'opérateur d'incrémentation normale `++var` est déclaré normalement.
- Pour la différence avec le **post incrémentation** `var++`, remarquer l'ajout
  d'une variable `int` dans les arguments.
- L'opérateur de surchage doit être déclarer à l'**extérieur de la classe**.

- Ainsi, si on veut que cet opérateur puisse accéder aux attributs privés, il
  doit être déclaré comme `fonction amie`.

```cpp
 friend ostream & operator<<(ostream& , const Counter &);
```


Avec cette déclaration, on peut utiliser facilement comme suit:

```cpp
int main() {
  Counter c;

  // Augmenter la valeur de c par 1
  ++c;
  cout<< c<<endl;

  // Augmenter la valeur de c par 4
  c += 5;
  cout<< c << endl;

  return 0;
}
```

###   [Binary operators](#binary)
<a name='binary'></a>

Pour illustrer les opérateurs **binaires**, on invoque un classique qui est
celui d'une classe de nombre complexes. Le but est d'implémenter tous les
opérateurs mathématiques `+,-, *, /` pour cet classe.


```cpp
class Complex
{
public:

    Complex( double r =0, double im= 0):real_(r),imag_(im){};


    //operators
    Complex operator+(Complex & other)
    {
        return Complex(this->real_ + other.real_, 
                this->imag_ + other.imag_);
    }


    friend ostream& operator<<(ostream&, const Complex &);

private:
    /* data */
    double real_;
    double imag_;
};


ostream& operator<<(ostream& out, const Complex & C)
{
    out <<"("<< C.real_ <<"+ "<<C.imag_<<"j)";
    return out;
}

int main(int argc, char *argv[])
{
  Complex C1(2, 1);
  Complex C2(4, 3);
  

  //Ajouter C1 et C2
  auto C3 = C1 + C2;

  cout<< C1 <<" + " << C2 << "= "<< C3 <<endl;
  return 0;
}
```

Remarquer que l'appel de l'instruction ` C3 = C1 + C2` implicitement invoque
l'appel de l'opérateur comme illustré dans la figure:

<div class="figcenter">

<img src="{{ site.url }}{{ site.baseurl }}/part3/images/cpp-operator-overloading.webp" width="400" height="400">


</div>


##  [Templates](#templates)
<a name='templates'></a>
