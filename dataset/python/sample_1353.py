def process_data(data):
    state = 'init'
    for item in data:
        if state == 'init':
            if item == 'connect':
                state = 'connected'
            elif item == 'disconnect':
                state = 'disconnected'
        elif state == 'connected':
            if item == 'data':
                state = 'processing'
            elif item == 'disconnect':
                state = 'disconnected'
        elif state == 'processing':
            if item == 'complete':
                state = 'connected'
            elif item == 'disconnect':
                state = 'disconnected'
        elif state == 'disconnected':
            if item == 'connect':
                state = 'connected'
    return state

def main():
    data_sequence = ['connect', 'data', 'complete', 'disconnect']
    result = process_data(data_sequence)
    print(result)
if __name__ == '__main__':
    main()