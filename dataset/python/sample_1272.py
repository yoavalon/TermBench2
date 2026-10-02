def network_state_machine():
    states = ['idle', 'connected', 'failed']
    transitions = {'idle': 'connected', 'connected': 'failed', 'failed': 'idle'}
    state = 'idle'
    for _ in range(3):
        state = transitions[state]
    return state
network_state_machine()