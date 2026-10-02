def seq_gen(n):
    a, b = (0, 1)
    sequence = []
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence

def consensus_mechanism(seq):
    result = []
    for i in range(1, len(seq)):
        diff = seq[i] - seq[i - 1]
        result.append(diff)
    return result

def main():
    n = 10
    sequence = seq_gen(n)
    consensus = consensus_mechanism(sequence)
    print(consensus)
main()