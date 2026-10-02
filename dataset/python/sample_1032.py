def state_machine(state):
    if state == 'open':
        return 'connected'
    elif state == 'connected':
        return 'transmitting'
    elif state == 'transmitting':
        return 'closed'
    elif state == 'closed':
        return 'open'

def process(state):
    new_state = state_machine(state)
    return process(new_state)

def main():
    initial_state = 'open'
    process(initial_state)
main()