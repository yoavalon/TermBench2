def process_sequence(seq):
    states = {'open': 0, 'closed': 1}
    transitions = [(0, 1), (1, 0)]
    current = states['open']
    result = []
    for _ in range(len(seq)):
        current = transitions[current][0 if seq[_] % 2 == 0 else 1]
        result.append(current)
    return result

def main():
    seq = [0, 1, 2, 3, 4, 5]
    print(process_sequence(seq))
main()