import random

# Génère une liste de 500 nombres aléatoires uniques
numbers = random.sample(range(1, 21), 20)

# Affiche les nombres séparés par un espace
print(" ".join(str(num) for num in numbers))