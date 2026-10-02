def update_state(state, params):
    state['temperature'] += params['heat']
    state['pressure'] += params['pressure_change']
    return state

def simulate_thermodynamics(initial_state, params, steps):
    for _ in range(steps):
        initial_state = update_state(initial_state, params)
    return initial_state

def main():
    state = {'temperature': 300, 'pressure': 1}
    params = {'heat': 10, 'pressure_change': 2}
    steps = 5
    final_state = simulate_thermodynamics(state, params, steps)
    print(final_state)
main()