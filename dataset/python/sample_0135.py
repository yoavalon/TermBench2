def process_data(data, state):
    if state == 'open':
        if 'error' in data:
            return 'error'
        elif 'close' in data:
            return 'closed'
    elif state == 'error':
        if 'retry' in data:
            return 'open'
        elif 'close' in data:
            return 'closed'
    return state

def main():
    state = 'open'
    data_stream = ['open', 'data', 'data', 'error', 'retry', 'data', 'close']
    for data in data_stream:
        state = process_data(data, state)
        if state == 'closed':
            break
main()