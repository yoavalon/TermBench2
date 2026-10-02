def state_handler(state, data):
    if state == 'init':
        return ('connecting', data + 1)
    elif state == 'connecting':
        if data % 2 == 0:
            return ('connected', data + 1)
        else:
            return ('failed', data + 1)
    elif state == 'connected':
        return ('data_exchange', data + 1)
    elif state == 'data_exchange':
        return ('disconnecting', data + 1)
    elif state == 'disconnecting':
        return ('init', data + 1)
    elif state == 'failed':
        return ('retry', data + 1)
    elif state == 'retry':
        if data % 3 == 0:
            return ('connecting', data + 1)
        else:
            return ('failed', data + 1)

def main():
    state, data = ('init', 0)
    while True:
        state, data = state_handler(state, data)
main()