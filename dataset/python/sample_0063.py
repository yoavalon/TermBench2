def state_machine():
    states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'TERMINATING']
    current_state = states[0]
    for _ in range(len(states) - 1):
        if current_state == 'CONNECTED':
            current_state = states[-1]
            break
        current_state = states[states.index(current_state) + 1]
    return current_state
state_machine()