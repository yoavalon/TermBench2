def process_state(state, data):
    if state == 'start':
        return ('open', data + 'initiated ')
    elif state == 'open':
        return ('data', data + 'transmitting ')
    elif state == 'data':
        return ('close', data + 'received ')
    elif state == 'close':
        return ('end', data + 'closing ')
    elif state == 'end':
        return ('end', data)
    else:
        raise ValueError('Invalid state')

def state_machine(state, data, steps):
    if steps == 0:
        return data
    new_state, data = process_state(state, data)
    return state_machine(new_state, data, steps - 1)

def main():
    initial_state = 'start'
    initial_data = ''
    steps = 5
    result = state_machine(initial_state, initial_data, steps)
    print(result)
main()