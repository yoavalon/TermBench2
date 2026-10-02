class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DATA':
            self.state = 'DATA_RECEIVED'
        elif self.state == 'DATA_RECEIVED' and event == 'ACKNOWLEDGE':
            self.state = 'ACKNOWLEDGED'
        elif self.state == 'ACKNOWLEDGED' and event == 'DISCONNECT':
            self.state = 'DISCONNECTED'

class EventGenerator:

    def generate_events(self):
        while True:
            yield 'CONNECT'
            yield 'DATA'
            yield 'ACKNOWLEDGE'
            yield 'DISCONNECT'

class NetworkAnalyzer:

    def __init__(self):
        self.connection = ConnectionState()
        self.event_gen = EventGenerator()

    def analyze(self):
        for event in self.event_gen.generate_events():
            self.connection.transition(event)
            print(f'Current state: {self.connection.state}')

def main():
    analyzer = NetworkAnalyzer()
    analyzer.analyze()
main()