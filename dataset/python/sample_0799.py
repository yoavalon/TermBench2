def state_machine(state, data):
    if state == 0:
        if data == 'open':
            return (1, 'Connection opened')
        else:
            return (0, 'Invalid data')
    elif state == 1:
        if data == 'close':
            return (2, 'Connection closed')
        else:
            return (1, 'Data ignored')
    elif state == 2:
        return (2, 'Connection already closed')

def process_data(data_sequence):
    state = 0
    result = []
    for data in data_sequence:
        state, message = state_machine(state, data)
        result.append(message)
    return result

def main():
    sequence = ['open', 'send', 'close', 'send']
    print(process_data(sequence))
main()