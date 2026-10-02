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
            self.process_data()
        elif self.state == 'idle' and event == 'data':
            pass

    def process_data(self):
        print('Processing data in state:', self.state)

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'disconnect', 'data', 'connect', 'data', 'disconnect']

    def generate(self):
        return self.events.pop(0) if self.events else 'idle'

class NetworkManager:

    def __init__(self):
        self.state_machine = StateMachine()
        self.event_generator = EventGenerator()

    def run(self):
        while True:
            event = self.event_generator.generate()
            self.state_machine.transition(event)

def main():
    network_manager = NetworkManager()
    network_manager.run()
main()