def state_handler(current_state):
    if current_state == 'INITIAL':
        return 'LISTENING'
    elif current_state == 'LISTENING':
        return 'SYN_RECEIVED'
    elif current_state == 'SYN_RECEIVED':
        return 'ESTABLISHED'
    elif current_state == 'ESTABLISHED':
        return 'CLOSE_WAIT'
    elif current_state == 'CLOSE_WAIT':
        return 'LAST_ACK'
    elif current_state == 'LAST_ACK':
        return 'CLOSED'
    else:
        return 'ERROR'

def main():
    state = 'INITIAL'
    while True:
        state = state_handler(state)
main()