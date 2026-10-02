def state_machine():
    states = ['init', 'open', 'data', 'close']
    transitions = {'init': 'open', 'open': 'data', 'data': 'close', 'close': 'open'}
    current_state = states[0]
    while True:
        current_state = transitions[current_state]
state_machine()