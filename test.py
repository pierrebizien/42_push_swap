import random

# Génère une liste de 500 nombres aléatoires uniques
numbers = random.sample(range(1, 501), 500)

# Affiche les nombres séparés par un espace
print(" ".join(str(num) for num in numbers))