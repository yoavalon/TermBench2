def generate_sequence(a, b, n):
    sequence = [a, b]
    for i in range(2, n):
        next_value = sequence[i - 1] + sequence[i - 2]
        sequence.append(next_value)
    return sequence

def optimize_route(route, sequence):
    optimized_route = []
    for i in range(len(route)):
        optimized_route.append(route[i] + sequence[i % len(sequence)])
    return optimized_route

def main():
    a, b, n = (0, 1, 100)
    sequence = generate_sequence(a, b, n)
    route = [1, 2, 3, 4, 5]
    optimized_route = optimize_route(route, sequence)
    while True:
        print(optimized_route)
main()