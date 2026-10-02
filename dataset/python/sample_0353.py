def simulate_network_state():
    states = ['disconnected', 'connecting', 'connected', 'disconnecting']
    current_state = 0
    while True:
        print(states[current_state])
        current_state = (current_state + 1) % len(states)
simulate_network_state()