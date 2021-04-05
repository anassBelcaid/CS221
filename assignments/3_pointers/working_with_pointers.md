---
layout :  page
title  :  Working with pointers
date   :  2021/04/04  
permalink : /asspointers/
---


## Liste d'exercice.


1. [Grasping](#grasping)
    - [v1v2p1p2](#v1v2p1p2)
    - [parameterMystery1](#parmystery1)
    - [parameterMystery2X](#parmystery2)

2. [Arrays using pointers](#arrays)
    - [Pivot Index](#pivotIndex)
    - [Largest Number](#largestNumber)
    - [Plus One](#PlusOne)

## [Grasping](#grasping)
<a name='grasping'></a>


## [V1V2P1P2](#v1v2p1p2)
<a name='v1v2p1p2'></a>

Dans l'exercice
[v1v2p1p2](https://www.codestepbystep.com/problem/view/cpp/pointers/v1v2p1p2),
on vous demande d'éxécuter le programme suivant et de donner leur **résultat**.

```cpp
int v1 = 10;
int v2 = 25;
int *p1 = &v1;
int *p2 = &v2;

*p1 += *p2;
p2 = p1;
*p2 = *p1 + *p2;

cout<< v1 << " " << v2 << endl;
cout<< *p1 <<" " << *p2 << endl;
```


## [parameterMystery1](#parmystery1)
<a name='parameterMystery1'>

Dans l'exercice [ParameterMystery1](https://www.codestepbystep.com/problem/view/cpp/pointers/parameterMystery1), on vous demande de produire le résultat du programme suivant:

```cpp
int parameterMystery1(int a, int &b, int* c)
{
 b++;
 a += *c;

 cout<< b << " "<< *c<< " " << a << " " << c << endl;

 c = &a;
 return a-b;
}

int main()
{
  int a = 4;
  int b = 8;
  int c = -3;
  int d;

  d = parameterMystery1(a, b, &c);

  parameterMystery1(c, d, &b);
  parameterMystery1(b, a, &d);

  cout<< a <<" " << b << " " << c <<" " <<d << endl;
}
```

Pour unifier le résultat, on suppose que les les variables sont stockées dans
les mémoires suivantes:

- a est stockée dans `0xaa00`
- b est stockée dans `0xbb00`
- c est stockée dans `0xcc00`
- d est stockée dans `0xdd00`

## [parameterMystery2X](#parmystery2)
<a name='parmystery2'>

Similaire à l'exércice précédant, dans
[ParamterMyster2](https://www.codestepbystep.com/problem/view/cpp/pointers/parameterMystery2X),
on vous demande de produire le résultat du programme suivant:


```cpp
string * parameterMyster2X(string & s1, string s2)
{
    s1 += "1";
    s2 += "2";

    cout<< s2 << " -- " << s1 <<endl;
    s1 += "!!!";

    return &s1;
}

int main()
{
    string s1 = "hi";
    string s2 = "bye";
    string s3 = "yo";

    string * s4 = new string(s3);
    string* s5 = nullptr;

    parameterMyster2X(s1, s3);
    s5 = parameterMyster2X(*s4, s2);
    parameterMyster2X(s2, *s5);

    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    cout<<s4<< " " << *s4 << " " << s5 << *s5 << endl;
}
```

Les espaces mémoires des variables est le suivant:

- s1 est dans `0x1100`
- s2 est dans `0x2200`
- s3 est dans `0x3300`
- s4 est dans `0x4400`
- s5 est dans `0x5500`




## [Arrays using pointers](#arrays)
<a name='arrays'>

### [Pivot Index](#pivotIndex)
<a name='pivotIndex'>


### [Largest Number](#largestNumber)
<a name='largestNumber'>

### [Plus One](#PlusOne)
<a name='PlusOne'>

