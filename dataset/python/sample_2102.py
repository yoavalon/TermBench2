def network_state_machine():
    states = ['CONNECTING', 'CONNECTED', 'DISCONNECTING', 'DISCONNECTED']
    current_state = states[0]
    while True:
        if current_state == states[0]:
            current_state = states[1]
        elif current_state == states[1]:
            current_state = states[2]
        elif current_state == states[2]:
            current_state = states[3]
        elif current_state == states[3]:
            current_state = states[0]
network_state_machine()