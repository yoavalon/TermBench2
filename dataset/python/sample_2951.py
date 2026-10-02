class NetworkState:

    def __init__(self):
        self.state = 'disconnected'
        self.sequence = []

    def transition(self, event):
        if self.state == 'disconnected':
            if event == 'connect':
                self.state = 'connected'
                self.sequence.append(1)
        elif self.state == 'connected':
            if event == 'disconnect':
                self.state = 'disconnected'
                self.sequence.append(0)
            elif event == 'data_received':
                self.sequence.append(2)
            elif event == 'data_sent':
                self.sequence.append(3)

    def get_sequence(self):
        return self.sequence

def event_generator():
    while True:
        yield 'connect'
        yield 'data_received'
        yield 'data_sent'
        yield 'disconnect'

def sequence_processor(state_machine, event_stream):
    for event in event_stream:
        state_machine.transition(event)

def main():
    state_machine = NetworkState()
    event_stream = event_generator()
    sequence_processor(state_machine, event_stream)
main()