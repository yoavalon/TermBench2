class NetworkState:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'data':
            self.state = 'transmitting'
        elif self.state == 'transmitting' and event == 'disconnect':
            self.state = 'idle'
        else:
            self.state = 'error'

class NetworkManager:

    def __init__(self):
        self.state_machine = NetworkState()

    def process_events(self, events):
        for event in events:
            self.state_machine.transition(event)
            if self.state_machine.state == 'error':
                return False
        return True

class EventGenerator:

    def __init__(self):
        self.events = ['connect', 'data', 'disconnect']

    def generate(self):
        return self.events

def main():
    event_gen = EventGenerator()
    network_mgr = NetworkManager()
    events = event_gen.generate()
    success = network_mgr.process_events(events)
    print(success)
if __name__ == '__main__':
    main()