def generate_sequence(state, sequence):
    if state == 0:
        next_state = 1
        next_value = sequence[-1] + 1
    elif state == 1:
        next_state = 2
        next_value = sequence[-1] * 2
    elif state == 2:
        next_state = 0
        next_value = sequence[-1] - 1
    return (next_state, next_value)

def main():
    state = 0
    sequence = [1]
    while True:
        state, value = generate_sequence(state, sequence)
        sequence.append(value)
main()