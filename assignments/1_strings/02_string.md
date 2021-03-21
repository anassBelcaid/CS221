---
layout :  page
title  :  Assignment on String
date   :  2021/03/23  
permalink: /ass1/
---

## Objectifs:

1. Se sentir comfortable à écrire  vos propres strucrues.
2. Ecrire des fonctions pour la manipulation des **string**.
3. Utiliser les **methodes** de la classe string.



## Structure Student

Votre tache est de créer une **structure** `Student` qui consiste de son
*age*, **nom**, **prénom** et sa **note**. Vous devez aussi écrire un programme
lit des données de **quatre** ligne:

```
integer : age de l'étudiant.
prénom  : chaine de caractères.
nom     : chaine de caractères.
note    : note de l'étudiant entier.
```

La **sortie** sera une seule ligne qui contient ces champs séparés par un
**espace**.

Par exemple si l'entrée est:

```
23
Adam
Hacker
20
```


la sortie sera:

```
23 Adam Hacker 10
```


## [ <img src="{{site.url }}{{ site.baseurl}}/assets/logo_step.png" width="30"> Add Commas](https://www.codestepbystep.com/problem/view/cpp/strings/addCommas)


Ecrire une fonction `addCommas` qui accepte une chaine qui représent un nombre
et qui renvoie une chaine qui contient une **virgule** à chaque troisième
position, en commençant par la **droite**. 

Par exemple 
```
addCommas(12345678)  ====> 12,345, 678
```


## [ <img src="{{site.url }}{{ site.baseurl}}/assets/logo_step.png" width="30"> Cesar Chyper](https://www.codestepbystep.com/problem/view/cpp/strings/caesarCipher)


Ecrire un programme (avec une fonction `main`) qui implémente le codage de
**César** avec une rotation indexé par une **clé**(cypher). Votre programme doit
demander à l'utilisateur la saisie d'un **message** puis une clé ( qui
représente le nombre de caractères à déplacer pour chaque lettre). Puis il
affiche le message **encodé**. 

**Exemples**

```shell
Your message? Attack zerg at dawn
Encoding key? 3
DWWDFN CHUJ DW GDZQ
```


```shell
Your message? DWWDFN CHUJ DW GDZQ
Encoding key? -3
ATTACK ZERG AT DAWN
```


## [ <img src="{{site.url }}{{ site.baseurl}}/assets/logo_step.png" width="30"> ConvertToAlt](https://www.codestepbystep.com/problem/view/cpp/strings/convertToAltCaps)

Write a function named convertToAltCaps that accepts a string as a parameter and returns a version of the string where alternating letters are uppercase and lowercase, starting with the first letter in lowercase. For example, the call of convertToAltCaps("Pikachu") should return "pIkAcHu". 


Ecrire une fonction `convertToAltCaps` qui admet un **string** comme paramètre
et qui renvoie une nouvelle version de ce string en altérant entre minuscule et
majuscule.

La première lettre doit être **minuscule**.


**Exemple**:

```shell
convertToAltCaps("Pikachu") ===> "pIkAcHu"
```


## [ <img src="{{site.url }}{{ site.baseurl}}/assets/logo_step.png" width="30"> Count words](https://www.codestepbystep.com/problem/view/cpp/strings/countWords)



Ecrire une fonction `countWords` qui accepte un **string** comme paramètre et
qui renvoie le **nombre de mots** dans celui ci.

Un mot est une succession de caractères (différent d'espace).



**Exemple**

```shell
auto v = countWords("What is your name?") =====> v=4
```

## [ <img src="{{site.url }}{{ site.baseurl}}/assets/logo_step.png" width="30"> IsAllVowels](https://www.codestepbystep.com/problem/view/cpp/strings/isAllVowels)



Ecire une fonction `isAllVowels` qui renvoie un **booléen** indiquant si la
chaine est composé seulement de voyelles(`a,e,i,o,u`) indépendamment de la casse.


**Exemple**

```shell
isAllVowels("eiEIo") ====> true
isAllVowels("banana" ====> false
```


