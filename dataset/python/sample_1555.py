def state_machine():
    states = ['init', 'conn', 'data', 'close']
    transitions = {'init': 'conn', 'conn': 'data', 'data': 'close', 'close': 'conn'}
    current_state = 'init'
    while True:
        current_state = transitions[current_state]
        print(current_state)
state_machine()