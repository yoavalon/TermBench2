def state_transition(state, input):
    if state == 'idle' and input == 'connect':
        return 'connecting'
    elif state == 'connecting' and input == 'acknowledged':
        return 'connected'
    elif state == 'connected' and input == 'disconnect':
        return 'disconnecting'
    elif state == 'disconnecting' and input == 'disconnected':
        return 'idle'
    return state

def process_inputs():
    current_state = 'idle'
    inputs = ['connect', 'acknowledged', 'disconnect', 'disconnected']
    while True:
        for input in inputs:
            current_state = state_transition(current_state, input)

def main():
    process_inputs()
main()