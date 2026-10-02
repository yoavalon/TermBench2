def generate_sequence(n):
    a, b = (0, 1)
    for _ in range(n):
        yield a
        a, b = (b, a + b)

def optimize_logistics(sequence):
    costs = []
    for value in sequence:
        cost = value ** 2 + 3 * value + 2
        costs.append(cost)
    return costs

def main():
    while True:
        seq = generate_sequence(10)
        costs = optimize_logistics(seq)
        print(costs)
main()