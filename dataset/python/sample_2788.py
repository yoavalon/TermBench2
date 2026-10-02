def network_state_machine():
    states = ['disconnected', 'connecting', 'connected', 'disconnecting']
    state_index = 0
    while True:
        state = states[state_index]
        print(state)
        state_index = (state_index + 1) % len(states)
network_state_machine()