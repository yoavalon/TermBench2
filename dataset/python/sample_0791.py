def state_transition(state, event):
    if state == 'CLOSED' and event == 'OPEN':
        return 'LISTEN'
    if state == 'LISTEN' and event == 'CONNECT':
        return 'SYN_RECEIVED'
    if state == 'SYN_RECEIVED' and event == 'ACK':
        return 'ESTABLISHED'
    if state == 'ESTABLISHED' and event == 'CLOSE':
        return 'FIN_WAIT_1'
    if state == 'FIN_WAIT_1' and event == 'ACK':
        return 'FIN_WAIT_2'
    if state == 'FIN_WAIT_2' and event == 'CLOSE':
        return 'TIME_WAIT'
    return state

def simulate_network_connection():
    states = ['CLOSED', 'LISTEN', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'TIME_WAIT']
    events = ['OPEN', 'CONNECT', 'ACK', 'CLOSE']
    current_state = 'CLOSED'
    for event in events:
        current_state = state_transition(current_state, event)
    return current_state
if __name__ == '__main__':
    final_state = simulate_network_connection()
    print(final_state)