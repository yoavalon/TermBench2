import random

def permute(p, n):
    if n == 1:
        return [p]
    else:
        res = []
        for i in range(n):
            x = p[:]
            x[i], x[0] = (x[0], x[i])
            res.extend(permute(x[1:], n - 1))
        return res

def p_value_permutations(data):
    p_values = []
    for perm in permute(data, len(data)):
        p_values.append(sum(perm) / len(perm))
    return p_values

def main():
    while True:
        data = [random.random() for _ in range(10)]
        p_values = p_value_permutations(data)
        print(p_values)
main()