cmake_minimum_required(VERSION 3.27)
project(PRG2_Recueil_Exercices C)

set(CMAKE_C_STANDARD 17)


add_executable(07-01-01-main C7_Types_avancés/07-01-01-Struct/07-01-01-main.c)
add_executable(07-02-01-main C7_Types_avancés/07-02-01-Enum/07-02-01-main.c)
add_executable(07-03-01-Union C7_Types_avancés/07-03-01-Union/07-03-01-main.c)
add_executable(07-04-01-Alignement C7_Types_avancés/07-04-01-Alignement/07-04-01-main.c)
add_executable(07-05-01-Const C7_Types_avancés/07-05-01-Const/07-05-01-main.c)

add_executable(08-01-01-Directives C8_Préprocesseur_et_compilation/08-01-01-Directives/08-01-01-main.c)
add_executable(08-02-01-Macros C8_Préprocesseur_et_compilation/08-02-01-Macros/08-02-01-main.c)
add_executable(08-02-02-Macros_avancees C8_Préprocesseur_et_compilation/08-02-02-Macros_avancées/08-02-02-main.c)

add_executable(09-02 C9_Fichiers/09-02-Fichiers-texte/09-02.c)
add_executable(09-03 C9_Fichiers/09-03-Fichiers-binaires/09-03.c)
add_executable(09-04-01 C9_Fichiers/09-04-Fichiers-et-buffers/09-04-01.c)
add_executable(09-04-02 C9_Fichiers/09-04-Fichiers-et-buffers/09-04-02.c)

add_executable(10-01 C10_Erreurs_et_tests/10-01.c)

add_executable(11-01 C11_Structures_de_donnees/11-01-Queue/11-01.c
        C11_Structures_de_donnees/11-01-Queue/queue.h
        C11_Structures_de_donnees/11-01-Queue/queue.c)

add_executable(11-02 C11_Structures_de_donnees/11-02-Queue/11-02.c
        C11_Structures_de_donnees/11-02-Queue/queue.c
        C11_Structures_de_donnees/11-02-Queue/queue.h)

add_executable(12-01 C12_Aspects_avancés_C/12-01/12-01.c)
add_executable(12-02 C12_Aspects_avancés_C/12-02/12-02.c)
add_executable(12-03 C12_Aspects_avancés_C/12-03/12-03.c)
