---
layout : page
title  :  Complexity practice
date   :  2021/04/11  
permalink: /complexitywork/
---
- [Evaluating Complexity](#eval)
    - [Big Oh 1](#bigOh1)
    - [Big Oh 2](#bigOh2)
    - [Big Oh 3](#bigOh2)

- [Search](#binary)
    - [linear Search](#linear)
    - [Adding Tests](#tests)
    - [Timing your function](#timing) 
    - [Binary Search](#binarySearch)
    - [Side By Side simulation](#sidebyside)

## [Evaluating Complexity](#eval)
<a name='eval'>

### [Big Oh 1](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh1)
<a name='bigOh1'>

Evaluer la complexité de chaque code suivant:


```cpp
//a)
int sum = 0; 
for(int i=0; i<=N+2; i++)
    sum++;

for(int j=1; j<=N*2; j++)
    sum += 5;
cout << sum << endl;
```


```cpp
//b)
int sum = 0;
for (int i = 1; i <= N - 5; i++)
    for(int j = 1; j<= N-5; j+=2)
        sum++;
cout<< sum <<endl;
```

```cpp
//c)
int sum = N;
for(int i = 0; i < 100000; i++)
{
    for(int j = 0; j <= i; j++)
        sum += N;

    for(int j = 1; j <= i; j++)
        sum += N;

    for(int j = 1; j <= i; j++)
        sum += N;
}

cout<< sum << endl;
```

```cpp
//d)
Vector<int> list;
for( int i = 1; i <= N * N; i++)
{
    for(int j = 1; j <= N; j++)
        list.add( i + j);
}

for( int i = 1; i <= 2 * N; i++)
    list.remove( liste.size() - 1);

cout << "done!" << endl;
```


```cpp
//e
HashSet<int> set1;
for( int i = 1; i <= N; i++)
    set1.add(i);

Set<int> set2;
for(int i = 1; i <= N; i++)
{
    set1.remove(i);
    set2.add(i + N);
}
cout << "done!" << endl;
```

### [Big Oh 2](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh2)
<a name'bigOh2'>

Même question, évaluer la complexité pour chaque code:


```cpp
// a)
int sum = 0;
for (int i = 1; i <= N - 2; i++)
{
    for (int j = 1; j <= i + 4; j++)
        sum++;
    sum++;
}

for( int i = 1; i <= 100; i++)
    sum++;

cout << sum << endl;
```

```cpp
// b)
int sum = 0; 
for (int i = 1; i <= N; i++)
{
    for(int j = 1; j <= N * N; j++)
        sum++;
    
    for(int j = 1; j <= 100; j++)
        sum++;
    
    for(int j = 1; j <= N; j++)
        sum++;

    sum++;
}
cout << sum << endl;
```

```cpp
//c)
int sum = 0;

for( int i = 1; i <= N; i++)
{
    for( int j = 1; j <= 100; j++)
        sum++;

}

for( int k = 1; k <= 1000; k++)
    sum++;

cout << sum << endl;
```


```cpp
// d)
Set<int> set;
for (int i = 1; i <= N * 2; i++)
    set.add(i);

for(int k : set)
    cout << k << endl;
cout << "done!" << endl;
```

```cpp
// e)
Vector<int> vec;
for( int i = 1; i <= N + 100; i++)
    vec.add(i);

Stack<int> stack;
while( !vec.isEmpty() )
{
    stack.push(vec[vec.size() - 1]);
    vec.remove(vec.size() - 1);
}

while( !stack.isEmpty() ) 
    stack.pop();

cout << "done!" << endl;
```


### [Big Oh 3](https://www.codestepbystep.com/problem/view/cpp/bigoh/bigoh3)
<a name='bigOh3'>


Evaluer la complexité des codes suivants:

```cpp
// a)
HashSet<int> set1
for( int i= 0; i < N; i++)
    set1.add(i);


Set<int> set2;
for( int n : set1)
    set2.add(n);

cout << "done!" << endl;
```

```cpp
//b)

Vector<int> list;

for( int i = 0; i < N; i++)
    list.insert(k0, i*i);

Set<int< set;
for (int k : list)
    set.add(k);

cout << "done!" <<endl;
```

```cpp
// C
Vector<int> list1;
for(int  i = 0; i < N; i++)
    list1.add(i);

Vector<int> list2;
for(int i = 0; i < N; i++)
{
    list2.insert(0, list1[0]);
    list1.remove(0);
}

cout << "done!" << endl;
```


```cpp
// d)
int sum = 0;
for (int i = 0; i < N * 2; i++)
    for(int j = 0; j < 100; j++)
        for(int k = 0; k < j*j*j; j++)
            sum++;
cout<< sum << endl;
```

```cpp
// e)
int sum = 0;
for(int i = 0; i < N * 2; i++)
    for(int j = 0; j < i/2; j++)
        for(int k = 0; k < N*N; k++)
            sum++;
cout << sum << endl;
```


## [Search](#binary)
<a name='binary'>

Le but de cette section, est de **coder** et de **visualiser** le temps
d'exécution des deux algorithmes de recheches dans un tableau **trié**.


> Le code de départ est dans <a href="{{ site.url }}{{site.baseurl}}/assignments/04_complexity/search.zip">search_simulation.zip</a>


### [linear Search](#linear)
<a name='linear'>

Comme première tache on va mesurer le temps d'exécution de la **recherche
linéaire**. Ainsi dans le fichier `tests.h`, completer l'implémentation
de la fonction

```cpp
int linear_search( vecI & nums)
{
  
}
```


### [Adding Tests](#tests)
<a name='tests'>

Avant de mesurer le temps d'exécution de votre fonction, on doit **s'assurer**
qu'elle est correcte. On va en profiter pour la notion de `tests` déja utilisée
dans le cours. On va se limiter à une fonction de test simple de `c++` qui est
l'instruction `assert` dans la bibliothèque [assert.h](http://www.cplusplus.com/reference/cassert/assert/), sa syntaxe est la suivante:


```cpp
assert( boolean expression);
```


Par exemple, l'instruction `assert( 1 == 1)`, ne va rien afficher et va
continuer, cependant, l'instruction `assert( 1 == 0 )` va générer une erreur
d'exécution.


Dans le header `tests.h`, vous trouverez une fonction ` void tests`. Le rôle de
cette fonction est de vérifier si votre fonction renvoie un résultat
**correcte**.

```cpp
void tests(int (*F)(vecI &, int) )
{

}
```

Par exemple on peut ajouter le code suivant pour tester notre fonction:

```cpp
//Vecteur simple
vecI nums{1,2,7, 8, 9, 12};

//calculer la valeur de la fonction de recherche pour 8
auto index = F(nums, 8)

//S'assurer que index est 3
assert( index == 3);

//Afficher un message de success
cout << "Test 1 success" << endl;
```


Votre rôle est d'ajouter d'autres tests pour être rigoureux:

- Ajouter un test qui **ne trouve** pas de valeur.
- Ajouter un test où le tableau est **vide**.
- Ajouter un test où la valeur est à la **fin**.
- Ajouter un test conteant **10 valeurs**.


### [Timing your function](#timing) 
<a name='timing'>

Maintenant qu'on a assuré que notre fonction est correcte, on dois mesurer son
temps d'exécution. On sait déja qu'elle est **linéaire**, cependant on va
mesurer cet aspet.

Afin de mesurer le temps d'exécution en `c++`, on utilise la classe
`high_resolution_clock` de la bibliothèque
[chrono](https://en.cppreference.com/w/cpp/chrono/high_resolution_clock). Cette
d'obtenir l'heure du système avec une grande précision.


Chercher la documentation de cette fonction, pour obtenir le temps d'exécution
d'une fonction.

Ainci dans le fichier `simulation.cpp`, compléter le code de cette fonction.



```cpp
double timing(int(*F)(vecI &, int), vecI & nums, int target)
{
    //Mesurer le temps de la fonction F pour chercher target dans le vecteur
    // nums
}

```


### [Binary Search](#binarySearch)
<a name='binarySearch'>

Maintenant, on paut passer à l'implémentation de la fonction de **recherche
dichotomique**. Ainsi, dans le fichier `tests.h`, implémenter cette recherche
dans la fonction `binary_search`.


> Pour tester votre function changer l'appel de test par 

```cpp
tests(&binary_search)
```

### [Side By Side simulation](#sidebyside)
<a name='sidebyside'>

finalement, vous avez deux versions de recherche qui sont correctes. Votre
dernière question consiste à générer une table des temps d'exécution de chaque
fonction. 

Vous commencer de $$N=100$$ et à chaque fois, vous doubler cette taille.

<style type="text/css">
.tg  {border-collapse:collapse;border-color:#ccc;border-spacing:0;}
.tg td{background-color:#fff;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;overflow:hidden;padding:1px 2px;word-break:normal;}
.tg th{background-color:#f0f0f0;border-color:#ccc;border-style:solid;border-width:1px;color:#333;
  font-family:Arial, sans-serif;font-size:14px;font-weight:normal;overflow:hidden;padding:1px 2px;word-break:normal;}
.tg .tg-buh4{background-color:#f9f9f9;text-align:left;vertical-align:top}
.tg .tg-0lax{text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-0lax">Size </th>
    <th class="tg-0lax">Time linear<br></th>
    <th class="tg-0lax">time binary</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-buh4">100</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
  <tr>
    <td class="tg-0lax">200</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-buh4">400</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
  <tr>
    <td class="tg-0lax">...</td>
    <td class="tg-0lax"></td>
    <td class="tg-0lax"></td>
  </tr>
  <tr>
    <td class="tg-buh4">6400</td>
    <td class="tg-buh4"></td>
    <td class="tg-buh4"></td>
  </tr>
</tbody>
</table>

