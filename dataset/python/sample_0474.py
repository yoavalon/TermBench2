def state_machine(data):
    state = 0
    while True:
        if state == 0:
            state = 1 if 'SYN' in data else state
        elif state == 1:
            state = 2 if 'ACK' in data else state
        elif state == 2:
            state = 3 if 'SYN' in data else state
        elif state == 3:
            state = 4 if 'ACK' in data else state
        yield state

def process_data():
    data_stream = ['SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK']
    machine = state_machine(data_stream)
    for state in machine:
        print(f'Current State: {state}')
process_data()