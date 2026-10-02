def state_machine(initial_state, transitions, input_sequence):
    current_state = initial_state
    for signal in input_sequence:
        if (current_state, signal) in transitions:
            current_state = transitions[current_state, signal]
        else:
            raise ValueError('Invalid state transition')
    return current_state

def process_network_data(data):
    initial = 'idle'
    transitions = {('idle', 'open'): 'connected', ('connected', 'data'): 'data_transfer', ('data_transfer', 'close'): 'closing', ('closing', 'ack'): 'closed'}
    final_state = state_machine(initial, transitions, data)
    if final_state != 'closed':
        raise Exception('Network connection did not terminate properly')
if __name__ == '__main__':
    sequence = ['open', 'data', 'close', 'ack']
    process_network_data(sequence)