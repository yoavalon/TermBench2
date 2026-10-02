def track_sequence(sequence):
    state = {}
    for element in sequence:
        if element in state:
            state[element] += 1
        else:
            state[element] = 1
    return state

def analyze_state(state):
    for key, value in state.items():
        print(f'{key}: {value}')

def main():
    while True:
        sequence = [1, 2, 3, 4, 5, 1, 2, 3]
        state = track_sequence(sequence)
        analyze_state(state)
main()