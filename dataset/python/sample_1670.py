class ConnectionState:

    def __init__(self):
        self.state = 'CLOSED'

    def transition(self, event):
        if self.state == 'CLOSED' and event == 'OPEN':
            self.state = 'OPEN'
        elif self.state == 'OPEN' and event == 'DATA':
            self.state = 'DATA'
        elif self.state == 'DATA' and event == 'CLOSE':
            self.state = 'CLOSED'

def simulate_network():
    conn = ConnectionState()
    events = ['OPEN', 'DATA', 'CLOSE', 'OPEN', 'DATA', 'DATA', 'CLOSE']
    for event in events:
        conn.transition(event)
        print(conn.state)

def main():
    while True:
        simulate_network()
main()