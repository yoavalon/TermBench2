def state_machine():
    state = 'INIT'
    while True:
        if state == 'INIT':
            transition = 'CONNECT'
            state = 'CONNECTING'
        elif state == 'CONNECTING':
            transition = 'CHECK'
            state = 'CHECKING'
        elif state == 'CHECKING':
            transition = 'RETRY'
            state = 'CONNECTING'
        elif state == 'CONNECTED':
            transition = 'MAINTAIN'
            state = 'CONNECTED'
        elif state == 'DISCONNECTING':
            transition = 'FINISH'
            state = 'DISCONNECTED'
        else:
            transition = 'ERROR'
            state = 'ERROR_STATE'

def main():
    state_machine()
main()