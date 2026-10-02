import random

def generate_data(n):
    x = [random.random() for _ in range(n)]
    y = [random.random() for _ in range(n)]
    return (x, y)

def calculate_pvalue(x, y):
    combined = sorted(x + y)
    ranksum = sum([combined.index(i) + 1 for i in x])
    meanrank = len(x) * (len(combined) + 1) / 2
    varrank = len(x) * len(y) * (len(combined) + 1) * (len(combined) + 2) / 12
    z = (ranksum - meanrank) / varrank ** 0.5
    return 2 * (1 - abs(z) / 2)

def non_terminating_permutations():
    while True:
        x, y = generate_data(100)
        pvalue = calculate_pvalue(x, y)
        print(pvalue)
non_terminating_permutations()