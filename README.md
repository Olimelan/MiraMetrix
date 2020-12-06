# MiraMetrix

Ce programme lance la console et demande a l'utilisateur de choisir entre changer de channel sur un vidéo webcam ou modifier des images, les images doivent être dans le même documents que le projet pour fonctionner.

Deux classes ont été créé pour gérer les images et le feed webcam (présent dans imageTest et webcamTest) et qui regroupe les attributs et les foncions appropriées pour les objectifs du test, entre autre, elle permette rapidement d'appliqué un channel spécifique sur l'object en question et permet d'avoir plus qu'une fenêtre en même temps d'ouverte avec les mêmes fonctionnalités pour des appliquations futures.

Settings:

Les includes doivent pointer vers la librairies de opencv sur votre ordinateur.

Visual studio 2019 project properties configurations
- set environements variables and path in your computer to the correct opencv location
- set solutions platform to x64
- set vc++/include directories to the include file of opencv
- set vc++/library directories to the lib file of opencv (vc15 is use) for the release and debug
- set Linker/input/additionnal dependencies to opencv and copy the lib file name (d for debug, and release for the rest)
- make sure the #include opencv/opencv.cpp is working before compiling the code


Le code fonctionne sur la platforme windows x64.
