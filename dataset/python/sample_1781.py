class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.connection = None

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.connection = 'active'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
            self.connection = None
        elif self.state == 'connected' and event == 'data':
            self.state = 'processing'
        elif self.state == 'processing' and event == 'complete':
            self.state = 'connected'

class Network:

    def __init__(self):
        self.sm = StateMachine()

    def process_events(self, events):
        for event in events:
            self.sm.transition(event)

class Processor:

    def __init__(self):
        self.network = Network()

    def run(self):
        while True:
            events = ['connect', 'data', 'complete', 'disconnect']
            self.network.process_events(events)

def main():
    processor = Processor()
    processor.run()
main()