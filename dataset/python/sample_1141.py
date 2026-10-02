class NetworkState:

    def __init__(self):
        self.state = 'idle'
        self.buffer = []

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.buffer.append('connection established')
        elif self.state == 'connected' and event == 'data':
            self.state = 'data_received'
            self.buffer.append('data received')
        elif self.state == 'data_received' and event == 'disconnect':
            self.state = 'idle'
            self.buffer.append('disconnected')

class NetworkHandler:

    def __init__(self, state_machine):
        self.machine = state_machine

    def handle_event(self, event):
        self.machine.transition(event)

class NetworkMonitor:

    def __init__(self, handler):
        self.handler = handler

    def monitor(self):
        events = ['connect', 'data', 'disconnect']
        while True:
            for event in events:
                self.handler.handle_event(event)

def main():
    state_machine = NetworkState()
    handler = NetworkHandler(state_machine)
    monitor = NetworkMonitor(handler)
    monitor.monitor()
main()