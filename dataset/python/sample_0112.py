def process_state(state, data):
    if state == 'start':
        return ('connect', data)
    elif state == 'connect':
        if data == 'success':
            return ('data_transfer', data)
        else:
            return ('error', data)
    elif state == 'data_transfer':
        if data == 'complete':
            return ('disconnect', data)
        else:
            return ('data_transfer', data)
    elif state == 'error':
        return ('disconnect', data)
    elif state == 'disconnect':
        return ('end', data)
    else:
        return ('end', data)

def run_network_protocol(data_sequence):
    current_state = 'start'
    for data in data_sequence:
        current_state, data = process_state(current_state, data)
        if current_state == 'end':
            break
if __name__ == '__main__':
    run_network_protocol(['success', 'complete'])