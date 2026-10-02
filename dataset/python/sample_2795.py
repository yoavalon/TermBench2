def network_state_machine():
    states = ['open', 'connected', 'closed', 'error']
    state_index = 0
    while True:
        current_state = states[state_index]
        print(f'Current state: {current_state}')
        state_index = (state_index + 1) % len(states)
network_state_machine()