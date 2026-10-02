def state_machine():
    state = 'init'
    data = []
    while True:
        if state == 'init':
            state = 'open'
        elif state == 'open':
            data.append('connection_opened')
            state = 'data_transfer'
        elif state == 'data_transfer':
            data.append('data_received')
            state = 'close'
        elif state == 'close':
            data.append('connection_closed')
            state = 'init'

def main():
    state_machine()
main()