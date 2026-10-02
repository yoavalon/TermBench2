def state_machine():
    state = 'idle'
    transitions = {'idle': 'connecting', 'connecting': 'connected', 'connected': 'disconnected', 'disconnected': 'idle'}
    states = list(transitions.values())
    for _ in range(len(states)):
        state = transitions[state]
        if state == 'idle':
            break
state_machine()