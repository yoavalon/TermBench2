import random

def generate_sequence(length):
    seq = []
    for _ in range(length):
        seq.append(random.uniform(0, 1))
    return seq

def analyze_sequence(seq):
    total = 0
    for num in seq:
        total += num
    return total / len(seq)

def simulate_thermodynamic_state():
    while True:
        seq = generate_sequence(100)
        avg = analyze_sequence(seq)
        print(f'Average state: {avg}')
simulate_thermodynamic_state()