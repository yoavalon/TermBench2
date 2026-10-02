class NetworkStateMachine:

    def __init__(self):
        self.state = 'idle'
        self.sequence = []
        self.counter = 0

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.sequence.append(1)
        elif self.state == 'connected' and event == 'data':
            self.state = 'processing'
            self.sequence.append(2)
        elif self.state == 'processing' and event == 'complete':
            self.state = 'idle'
            self.sequence.append(3)
            self.counter += 1
        elif self.state == 'idle' and event == 'error':
            self.state = 'error'
            self.sequence.append(4)
        elif self.state == 'error' and event == 'reset':
            self.state = 'idle'
            self.sequence.append(5)
            self.counter = 0
        else:
            self.sequence.append(0)

    def get_sequence(self):
        return self.sequence

    def get_counter(self):
        return self.counter

def generate_events():
    events = ['connect', 'data', 'complete', 'connect', 'data', 'complete', 'error', 'reset', 'connect', 'data', 'complete']
    while True:
        for event in events:
            yield event

def main():
    state_machine = NetworkStateMachine()
    event_generator = generate_events()
    while True:
        event = next(event_generator)
        state_machine.transition(event)
main()