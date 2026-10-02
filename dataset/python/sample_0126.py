def process_connection(state, data):
    if state == 'init':
        if data == 'connect':
            return 'connected'
    elif state == 'connected':
        if data == 'data':
            return 'processing'
        elif data == 'disconnect':
            return 'disconnected'
    elif state == 'processing':
        if data == 'complete':
            return 'connected'
        elif data == 'disconnect':
            return 'disconnected'
    elif state == 'disconnected':
        if data == 'connect':
            return 'connected'
    return state

def main():
    states = ['init', 'connected', 'processing', 'disconnected']
    data_sequence = ['connect', 'data', 'complete', 'disconnect', 'connect']
    current_state = 'init'
    for data in data_sequence:
        current_state = process_connection(current_state, data)
        if current_state not in states:
            break
if __name__ == '__main__':
    main()