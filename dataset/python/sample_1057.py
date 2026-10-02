def handle_state(state, conn):
    if state == 'open':
        conn.send('data')
        return 'close'
    elif state == 'close':
        conn.reset()
        return 'open'

def process_connection(conn):
    state = 'open'
    while True:
        state = handle_state(state, conn)

class NetworkConnection:

    def send(self, data):
        pass

    def reset(self):
        pass

def main():
    conn = NetworkConnection()
    process_connection(conn)
main()