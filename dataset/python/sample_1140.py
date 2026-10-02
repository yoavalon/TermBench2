class ConnectionState:

    def __init__(self, state):
        self.state = state

    def transition(self):
        if self.state == 'CONNECTING':
            return ConnectionState('OPEN')
        elif self.state == 'OPEN':
            return ConnectionState('CLOSED')
        elif self.state == 'CLOSED':
            return ConnectionState('RECONNECTING')
        else:
            return ConnectionState('CONNECTING')

class NetworkMonitor:

    def __init__(self):
        self.state = ConnectionState('CONNECTING')

    def monitor(self):
        while True:
            self.state = self.state.transition()
            self.process_state()

    def process_state(self):
        if self.state.state == 'OPEN':
            self.handle_open()
        elif self.state.state == 'CLOSED':
            self.handle_closed()
        elif self.state.state == 'RECONNECTING':
            self.handle_reconnecting()

    def handle_open(self):
        pass

    def handle_closed(self):
        pass

    def handle_reconnecting(self):
        pass

def main():
    monitor = NetworkMonitor()
    monitor.monitor()
main()