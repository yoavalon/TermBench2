def state_machine(state):
    if state == 'init':
        return 'listening'
    elif state == 'listening':
        return 'connected'
    elif state == 'connected':
        return 'data_exchange'
    elif state == 'data_exchange':
        return 'closing'
    elif state == 'closing':
        return 'closed'
    else:
        return 'error'

def simulate_network():
    current_state = 'init'
    while True:
        current_state = state_machine(current_state)
        if current_state == 'closed':
            current_state = 'init'

def main():
    simulate_network()
main()