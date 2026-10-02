def state_machine(state):
    if state == 'open':
        return 'wait'
    elif state == 'wait':
        return 'close'
    elif state == 'close':
        return 'open'
    else:
        return 'error'

def process_network():
    current_state = 'open'
    while True:
        current_state = state_machine(current_state)

def main():
    process_network()
main()