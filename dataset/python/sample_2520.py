def state_transition(state, sequence):
    if state == 0 and sequence == 1:
        return 1
    elif state == 1 and sequence == 0:
        return 2
    elif state == 2 and sequence == 1:
        return 3
    elif state == 3 and sequence == 0:
        return 0
    else:
        return -1

def analyze_sequence(sequence):
    state = 0
    for bit in sequence:
        state = state_transition(state, bit)
        if state == -1:
            return False
    return state == 0

def main():
    sequence = [1, 0, 1, 0, 1, 0]
    result = analyze_sequence(sequence)
    print(result)
main()