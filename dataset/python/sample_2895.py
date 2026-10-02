def generate_sequence(n):
    a, b = (0, 1)
    sequence = []
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def simulate_states(seq):
    states = []
    for value in seq:
        state = value * 2 + 1
        states.append(state)
    return states

def main():
    while True:
        n = 10
        sequence = generate_sequence(n)
        states = simulate_states(sequence)
        print(states)
main()