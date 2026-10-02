def state_machine_network():
    states = ['open', 'listening', 'connected', 'closing']
    transitions = {'open': 'listening', 'listening': 'connected', 'connected': 'closing', 'closing': 'open'}
    current_state = states[0]
    while True:
        current_state = transitions[current_state]
        print(current_state)
state_machine_network()