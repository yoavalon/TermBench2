def update_state(state, delta):
    return state + delta

def compute_sequence(steps, initial, increment):
    result = []
    current = initial
    for _ in range(steps):
        result.append(current)
        current = update_state(current, increment)
    return result

def main():
    steps = 10
    initial = 0
    increment = 1
    sequence = compute_sequence(steps, initial, increment)
    print(sequence)
main()