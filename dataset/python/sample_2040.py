class NetworkStateMachine:

    def __init__(self):
        self.state = 'disconnected'
        self.data = []

    def transition(self, event):
        if self.state == 'disconnected' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'send':
            self.data.append('data')
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'disconnected'
            self.data.clear()

    def process_events(self, events):
        for event in events:
            self.transition(event)

    def get_status(self):
        return (self.state, self.data)

def generate_events(count):
    import random
    events = []
    for _ in range(count):
        if random.random() < 0.3:
            events.append('connect')
        elif random.random() < 0.5:
            events.append('send')
        else:
            events.append('disconnect')
    return events

def main():
    state_machine = NetworkStateMachine()
    events = generate_events(100)
    state_machine.process_events(events)
    final_state, final_data = state_machine.get_status()
    print(final_state, final_data)
if __name__ == '__main__':
    main()