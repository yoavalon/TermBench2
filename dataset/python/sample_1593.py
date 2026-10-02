def network_state_machine():
    states = ['init', 'open', 'data', 'close']
    state = states[0]
    transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open'}
    while True:
        state = transitions[state]
        print(state)
network_state_machine()