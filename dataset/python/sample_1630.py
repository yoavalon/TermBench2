def process_data(state, packet):
    if state == 'open':
        if packet == 'SYN':
            return 'syn_received'
        elif packet == 'FIN':
            return 'close_wait'
    elif state == 'syn_received':
        if packet == 'ACK':
            return 'established'
    elif state == 'established':
        if packet == 'FIN':
            return 'close_wait'
    elif state == 'close_wait':
        if packet == 'ACK':
            return 'last_ack'
    elif state == 'last_ack':
        if packet == 'ACK':
            return 'closed'
    return state

def simulate_network():
    state = 'open'
    packets = ['SYN', 'ACK', 'FIN', 'ACK']
    for packet in packets:
        state = process_data(state, packet)
    while True:
        state = process_data(state, 'ACK')
simulate_network()