#!/bin/bash

# Script pour compiler et exécuter tous les fichiers .c dans le répertoire courant

for fichier_c in *.c; do
    nom_executable="${fichier_c%.c}"  # Retire l'extension .c
    gcc -c "$fichier_c"
    gcc -o "$nom_executable" "$fichier_c"
done

