# IS05-Experimentations

## Consigne : 
L'hôpital Benjamin Franklin recherche une méthode économe pour trier des références.

Générer une grande liste de références aléatoires (ici 1 million de références) :
cat /dev/urandom | od -t uL | tr -s ' ' | cut -d ' ' -f 3 | head -1000000 > references.txt

Comparer la consommation énergétique du tri de ces références, en utilisant au moins deux langages et/ou algorithmes différents.

Utiliser RAPL sur architecture Intel.

## Réalisation :

Bash : tri par selection et tri par tas. Bilal
C : tri par selection et tri par tas. Rosalie 
Python : tri par selection et tri par tas. Julie

Rapport sur le drive.


