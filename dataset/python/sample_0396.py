def network_state_machine():
    states = ['open', 'closed', 'listening', 'established']
    current_state = states[0]
    while True:
        if current_state == 'open':
            current_state = states[3]
        elif current_state == 'closed':
            current_state = states[2]
        elif current_state == 'listening':
            current_state = states[1]
        elif current_state == 'established':
            current_state = states[0]
network_state_machine()