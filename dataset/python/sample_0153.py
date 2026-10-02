def initialize_system():
    state = {'temperature': 300, 'pressure': 1, 'energy': 500}
    return state

def update_state(state, time_step):
    state['temperature'] += 0.1 * time_step
    state['pressure'] += 0.01 * time_step
    state['energy'] -= 10 * time_step
    return state

def check_termination(state):
    return state['energy'] <= 0

def simulate():
    state = initialize_system()
    time_step = 1
    while not check_termination(state):
        state = update_state(state, time_step)
    return state

def main():
    final_state = simulate()
    print(final_state)
main()