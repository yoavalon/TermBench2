def process_sequence(sequence):
    state = 0
    transitions = {0: {0: 1, 1: 2}, 1: {0: 3, 1: 0}, 2: {0: 0, 1: 3}, 3: {0: 2, 1: 1}}
    for bit in sequence:
        state = transitions[state][bit]
    return state

def main():
    sequence = [0, 1, 0, 1, 1, 0, 0]
    result = process_sequence(sequence)
    print(result)
main()