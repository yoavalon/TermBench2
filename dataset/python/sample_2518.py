def generate_sequence(n):
    seq = [1, 1]
    while len(seq) < n:
        seq.append(seq[-1] + seq[-2])
    return seq

def optimize_distribution(seq, demand):
    total_supply = sum(seq)
    if total_supply < demand:
        return 'Insufficient supply'
    else:
        return [seq[i] for i in range(len(seq)) if seq[i] <= demand]

def main():
    n = 10
    demand = 15
    sequence = generate_sequence(n)
    result = optimize_distribution(sequence, demand)
    print(result)
main()