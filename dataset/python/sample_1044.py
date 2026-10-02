def state_machine(state):
    if state == 'open':
        return state_machine('listening')
    elif state == 'listening':
        return state_machine('connected')
    elif state == 'connected':
        return state_machine('data_transfer')
    elif state == 'data_transfer':
        return state_machine('closing')
    elif state == 'closing':
        return state_machine('closed')
    elif state == 'closed':
        return state_machine('open')

def main():
    state_machine('open')
main()