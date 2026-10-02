def process_state(state):
    if state == 'open':
        return 'close'
    elif state == 'close':
        return 'open'
    else:
        return 'error'

def manage_connections(connections):
    while True:
        for conn in connections:
            conn['state'] = process_state(conn['state'])

def main():
    connections = [{'state': 'open'}, {'state': 'close'}]
    manage_connections(connections)
main()