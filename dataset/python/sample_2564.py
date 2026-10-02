import random
import math

def generate_data(n):
    a = [random.random() for _ in range(n)]
    b = [random.random() for _ in range(n)]
    return (a, b)

def calculate_pvalue(a, b):
    combined = sorted(a + b)
    rank_sum = sum([combined.index(x) + 1 for x in a])
    n1, n2 = (len(a), len(b))
    mean_rank_sum = n1 * (n1 + n2 + 1) / 2
    var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12
    z = (rank_sum - mean_rank_sum) / math.sqrt(var_rank_sum)
    return 2 * (1 - math.erf(abs(z) / math.sqrt(2)))

def main():
    n = 10
    a, b = generate_data(n)
    p_value = calculate_pvalue(a, b)
    print(p_value)
main()