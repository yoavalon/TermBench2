def state_machine():
    states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
    current_state = 0
    while True:
        current_state = (current_state + 1) % len(states)
        print(states[current_state])
state_machine()