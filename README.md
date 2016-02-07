# Knapsack-Allocation
## Lab Session - Dynamic programming for 0-1 knapsack problem and an allocation problem based on egg production. Developed in C.

### Organisation :
  Puisque le projet est séparé en deux parties, sur la programmation dynamique, nous avons crée deux dossier distincts, l'un pour le "Knapsack problem" et l'autre pour le problème d'allocation de ressources.
  
  
### Allocation problem :
  Les fonctions de l'algorithme permettant la résolution du problème se trouvent dans le fichier allocation.c
  Le fichier file.c contient les fonctions utiles à la lecture d'un fichiers de données au format texte.
  Le fichier tab_allocation.h et tab_allocation.h contiennent la structure contenant les données du problème et les fonctions permettant de la manipuler.
  Les fichiers others.h et others.c contiennent une fonction printdebug, affichant avec le même format qu'un printf (attribut de compilation pour gcc ajouté dans le .h afin de contrôler le respect de ce format) seulement si une variable préprocesseur DEBUG a pour valeur 1. Sinon la fonction printdebug n'a aucun effet. La variable DEBUG est définie lors de la compilation, l'option 'debug_full' du Makefile permet ainsi d'afficher un suivi du programme lors de son exécution, mais ralentit fortement celle-ci.
  
    En reprenant l'exemple du cours, nous avons procédé ainsi :
    	->
  
  
#### Instructions d'exécution :
  - Lancer le script Allocation.sh depuis un terminal permet de lancer l'exécution du programme avec le fichier allocation.txt. On peut également lancer le programme directement, avec un paramètre ou non (par défaut, c'est le fichier nommé allocation.txt qui est utilisé). 
- Pour utiliser d'autres fichiers, on peut soit modifier la ligne du scripts où le 'FILE_NAME' est définie,  avec le chemin d'un fichier existant (sans l'extension, qui doit être '.txt'), ou appeler directement le programme en ligne de commande avec le nom du fichier en paramètre.


### Knapsack problem :
  Le dossier "structures" contient les structures du programme --item et tab_knapsack-- et les fonctions associées à celles-ci.
  Le fichier knapsack.c contient les fonctions utiles à la résolution du probleme.
  Le fichier file.c contient les fonctions utiles à la lecture d'un fichiers de données au format texte.
  Les fichiers others.h et others.c sont également présents afin d'afficher d'avantage d'informations d'exécution, en utilise l'instruction "make debug_full"
  
  Afin de comparer les performances des différentes solutions de résolutions du "knapsack problem", le dossier "for_compare" contient les précédentes solutions mises en place ("Branch and bound" et "Linear Programming").

    En reprenant l'exemple du cours, nous avons procédé ainsi :
	-> Grâce à constraint, on sait quel item est déjà dans le sac : on ajoute ces items à x (le tableau de prensence des items que l'on modifie)
	-> On calcule totalPoidsItems, qui va indiquer s'il reste de la place dans le sac ou pas. S'il n'y a plus de place, on retourne 'u' (le probleme est fractionnel)
	-> On parcourt ensuite tous les items pour savoir lequel on ajoute au sac :
		--> Si l'item i à déjà une contrainte appliquée sur lui (constraint = 0 ou 1) alors on ne fait rien
		--> Sinon, l'item doit être traité :
			-> Soit l'item rentre entierement dans le sac et il reste de la place : on ajoute l'item au sac et on l'indique avec x{i]='1'
			-> Soit l'item rentre exactement dans le sac : on l'ajoute et on retourne 'i', la solution est entière
			-> Soit l'item ne rentre pas dans le sac et on doit fractionner :
				==> On calcule la proportion de l'item qui va dans le sac et on ajoute le profit correspondant dans objx.
				==> L'item n'est pas rentré en entier dans le sac donc x{i]='?', les items suivants ont x[i]='0'
				==> On retourne 'f', le probleme est fractionnel
	
#### Instructions de compilation :
- Utiliser la commande make dans un terminal compile le programme.
- L'option du Makefile 'debug_full' permet d'avoir les traces complètes lors de l'exécution.
- 'make clean' permet de nettoyer les fichier générés

#### Instructions d'exécution :
- Programme C :
	- Lancer les scripts DAVID_knapsack.sh et DEFAYE_knapsack.sh depuis un terminal permet de lancer l'exécution du programme avec le fichier .txt correspondant à l'étudiant.
	- Pour utiliser d'autres fichiers, on peut soit copier un des scripts et modifier la ligne où le 'STUDENT_NAME' est définie,  avec le nom d'un fichier qui aura été placé dans le dossier 'resources' au prélable (sans l'extension, qui doit être '.txt'), ou appeler directement le programme en ligne de commande avec le nom du fichier en paramètre.

#### Comparaison des solutions :
- GLPSOL :
	- Lancer les scripts glpsol_knapsack_DAVID.sh et glpsol_knapsack_DEFAYE.sh depuis un terminal permet de lancer l'exécution du solver glpsol sur avec le fichier .txt correspondant à l'étudiant. Ces scripts lancent le solver avec un fichier .ilp, contenant les parmètres et contraintes du problème, et un fichier .ilp avec les données sur lesquelles travailler.
	- Ces scripts vérifient qu'il existe de fichier ilp contenant les données (fichier contenant la partie 'data;' du problème) pour l'élève. Si ce fichier n'existe pas (il doit avoir un nom de la forme "[STUDENT_Name].data.ilp"), un script Perl prenant en paramètres le nom fichier texte et un nom de fichier de sortie est exécuté et génère le fichier de données à utiliser.
	- Pour utiliser d'autres fichiers texte, on peut ici aussi modifier le 'STUDENT_NAME' dans le script, avec le nom d'un fichier qui aura été placé dans le dossier 'resources'.
	- Les fichiers générés pas l'exécution de ces scripts peuvent être effacé avec l'exécution de 'make clean', depuis le dossier "for_compare".

#### Résultats : 
DEFAYE Johan : 
- Dynamic programming (Knapsack_Problem/DEFAYE_knapsack.sh) :
CPU time : 0.118000 seconds. ; 0.126000 seconds. ; 0.108000 seconds.
- Branch and bound (Knapsack_Problem/for_compare/DEFAYE_Branch_bound.sh) :
CPU time : 0.004000 seconds. ; 0.004000 seconds. ; 0.004000 seconds.
- ILP (glpsol_knapsack_DEFAYE.sh) :

DAVID Florian :
- Dynamic programming (Knapsack_Problem/DAVID_knapsack.sh) :
CPU time :  0.112000 seconds. ; 0.114000 seconds. ; 0.134000 seconds.
- Branch and bound (Knapsack_Problem/for_compare/DAVID_Branch_bound.sh) :
CPU time : 0.003000 seconds. ; 0.003000 seconds. ; 0.003000 seconds.
- ILP (glpsol_knapsack_DAVID.sh) :


### Problèmes rencontrés :

