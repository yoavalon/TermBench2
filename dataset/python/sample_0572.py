class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            self.state = 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DATA':
            self.state = 'ACTIVE'
        elif self.state == 'ACTIVE' and event == 'DISCONNECT':
            self.state = 'DISCONNECTED'
        elif self.state == 'DISCONNECTED' and event == 'ERROR':
            self.state = 'ERROR'

class EventGenerator:

    def __init__(self):
        self.events = ['CONNECT', 'DATA', 'DISCONNECT', 'ERROR']

    def generate(self):
        while True:
            for event in self.events:
                yield event

class NetworkAnalyzer:

    def __init__(self):
        self.connection = ConnectionState()
        self.events = EventGenerator()

    def analyze(self):
        for event in self.events.generate():
            self.connection.transition(event)
            if self.connection.state == 'ERROR':
                print('Error encountered, resetting state.')
                self.connection.state = 'DISCONNECTED'

def main():
    analyzer = NetworkAnalyzer()
    analyzer.analyze()
main()