def generate_sequence(n):
    sequence = []
    for i in range(1, n + 1):
        sequence.append(i * (i + 1) // 2)
    return sequence

def optimize_inventory(seq, target):
    for i, value in enumerate(seq):
        if value >= target:
            return (i, value)
    return (None, None)

def main():
    n = 10
    target = 20
    seq = generate_sequence(n)
    index, value = optimize_inventory(seq, target)
    if index is not None:
        print(f'Optimal index: {index}, Value: {value}')
    else:
        print('Target not met.')
main()