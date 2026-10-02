def update_state(state, delta):
    new_state = {}
    for key, value in state.items():
        new_state[key] = value + delta[key]
    return new_state

def simulate_system(initial_state, deltas):
    current_state = initial_state
    while True:
        for delta in deltas:
            current_state = update_state(current_state, delta)

def main():
    initial_state = {'temperature': 300, 'pressure': 1}
    deltas = [{'temperature': 10, 'pressure': -0.5}, {'temperature': -5, 'pressure': 0.25}]
    simulate_system(initial_state, deltas)
main()