def analyze_sequences():
    state = 0
    transitions = {0: 1, 1: 2, 2: 0}
    sequence = [state]
    for _ in range(10):
        state = transitions[state]
        sequence.append(state)
    return sequence
if __name__ == '__main__':
    result = analyze_sequences()
    print(result)