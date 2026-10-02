class ConnectionState:

    def __init__(self):
        self.state = 'disconnected'

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'
        elif self.state == 'connected' and event == 'data':
            self.state = 'processing'
        elif self.state == 'processing' and event == 'complete':
            self.state = 'connected'
        elif self.state == 'processing' and event == 'error':
            self.state = 'error'

    def get_state(self):
        return self.state

class NetworkManager:

    def __init__(self):
        self.connection = ConnectionState()
        self.events = ['connect', 'disconnect', 'data', 'complete', 'error']
        self.event_index = 0

    def generate_event(self):
        event = self.events[self.event_index % len(self.events)]
        self.event_index += 1
        return event

    def simulate_network(self):
        while True:
            event = self.generate_event()
            self.connection.transition(event)
            print(f'Event: {event}, State: {self.connection.get_state()}')

def main():
    network_manager = NetworkManager()
    network_manager.simulate_network()
main()