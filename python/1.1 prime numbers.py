import math

max_number = 10 ** 7
numbers = [j for j in range(1, max_number)]
numbers[0] = 0
for j in range(2, int(math.sqrt(float(max_number)))):
    if numbers[j] != 0:
        for i in range(2*j, max_number, j):
            numbers[i] = 0
for j in range(2, max_number):
    if numbers[j] != 0:
        print(numbers[j])