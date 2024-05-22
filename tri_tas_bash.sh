#!/bin/bash

# Chemin du fichier d'entr�e
input_file="references.txt"
# Chemin du fichier de sortie
output_file="references-tri-tas.txt"

# Lire le fichier et stocker les valeurs dans un tableau
mapfile -t references < "$input_file"

# Fonction pour ajuster le tas
construire_tas() {
    local -n arr=$1
    local n=$2
    local i=$3
    local largest=$i
    local l=$((2 * i + 1))
    local r=$((2 * i + 2))

    if [[ $l -lt $n && ${arr[$l]} -gt ${arr[$largest]} ]]; then
        largest=$l
    fi

    if [[ $r -lt $n && ${arr[$r]} -gt ${arr[$largest]} ]]; then
        largest=$r
    fi

    if [[ $largest != $i ]]; then
        # �change des �l�ments
        tmp=${arr[$i]}
        arr[$i]=${arr[$largest]}
        arr[$largest]=$tmp
        construire_tas arr $n $largest
    fi
}

# Fonction de tri par tas
tri_par_tas() {
    local -n arr=$1
    local n=${#arr[@]}

    # Construire un tas
    for ((i=n/2-1; i>=0; i--)); do
        construire_tas arr $n $i
    done

    # Extraire les �l�ments du tas
    for ((i=n-1; i>0; i--)); do
        # �changer l'�l�ment racine avec le dernier �l�ment
        tmp=${arr[0]}
        arr[0]=${arr[$i]}
        arr[$i]=$tmp
        construire_tas arr $i 0
    done
}

# Appliquer le tri par tas
tri_par_tas references

# �crire les r�sultats dans le fichier de sortie
for ref in "${references[@]}"; do
    echo "$ref" >> "$output_file"
done

echo "Le fichier tri� a �t� cr�� avec succ�s."
