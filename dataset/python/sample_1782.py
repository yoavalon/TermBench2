class NetworkState:

    def __init__(self):
        self.state = 'disconnected'
        self.connection_attempts = 0

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connecting'
        elif self.state == 'connecting':
            if event == 'success':
                self.state = 'connected'
                self.connection_attempts = 0
            elif event == 'failure':
                self.connection_attempts += 1
                if self.connection_attempts < 5:
                    self.state = 'connecting'
                else:
                    self.state = 'disconnected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'

class EventGenerator:

    def generate(self):
        import random
        if random.choice([True, False]):
            return 'connect'
        else:
            return 'disconnect'

class ConnectionHandler:

    def __init__(self):
        self.network = NetworkState()
        self.generator = EventGenerator()

    def run(self):
        while True:
            event = self.generator.generate()
            self.network.transition(event)
            if self.network.state == 'connected':
                self.handle_connected()
            elif self.network.state == 'disconnected':
                self.handle_disconnected()

    def handle_connected(self):
        print('Connected')

    def handle_disconnected(self):
        print('Disconnected')

def main():
    handler = ConnectionHandler()
    handler.run()
main()