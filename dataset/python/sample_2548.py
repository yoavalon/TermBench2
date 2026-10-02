def sequence_generator(n):
    a, b = (0, 1)
    for _ in range(n):
        yield a
        a, b = (b, a + b)

def thermodynamic_analysis(seq):
    total_energy = 0
    for value in seq:
        total_energy += value ** 2
    return total_energy

def main():
    n = 10
    seq = sequence_generator(n)
    energy = thermodynamic_analysis(seq)
    print(energy)
main()