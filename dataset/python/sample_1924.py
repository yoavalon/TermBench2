def process_data(data, state):
    if state == 'start':
        if data == 1:
            return ('connected', 1.0)
        else:
            return ('disconnected', 0.0)
    elif state == 'connected':
        if data == 0:
            return ('disconnected', 0.5)
        else:
            return ('connected', 1.5)
    else:
        return ('error', -1.0)

def main():
    state = 'start'
    data_sequence = [1, 0, 1, 0, 1]
    result = 0.0
    for data in data_sequence:
        state, value = process_data(data, state)
        result += value
    print(result)
main()