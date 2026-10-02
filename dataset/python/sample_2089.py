class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'
        self.data = 0.0

    def transition(self, event):
        if self.state == 'DISCONNECTED':
            if event == 'CONNECT':
                self.state = 'CONNECTED'
                self.data = 1.0
        elif self.state == 'CONNECTED':
            if event == 'TRANSMIT':
                self.data += 0.1
                if self.data >= 2.0:
                    self.state = 'DISCONNECTED'
                    self.data = 0.0
            elif event == 'DISCONNECT':
                self.state = 'DISCONNECTED'
                self.data = 0.0

    def get_state(self):
        return self.state

def simulate_network():
    states = ['CONNECT', 'TRANSMIT', 'DISCONNECT']
    conn = ConnectionState()
    for _ in range(10):
        event = states[_ % 3]
        conn.transition(event)
        if conn.get_state() == 'DISCONNECTED':
            break

def main():
    simulate_network()
if __name__ == '__main__':
    main()