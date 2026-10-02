def network_state_machine():
    state = 'init'
    while state != 'exit':
        if state == 'init':
            state = 'open'
        elif state == 'open':
            state = 'close'
        elif state == 'close':
            state = 'exit'
network_state_machine()