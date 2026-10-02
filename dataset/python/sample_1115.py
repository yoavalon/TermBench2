class StateMachine:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'open':
            if event == 'data':
                self.state = 'data_received'
            elif event == 'close':
                self.state = 'closed'
        elif self.state == 'data_received':
            if event == 'ack':
                self.state = 'acknowledged'
            elif event == 'error':
                self.state = 'error'
        elif self.state == 'acknowledged':
            if event == 'data':
                self.state = 'data_received'
            elif event == 'close':
                self.state = 'closed'
        elif self.state == 'error':
            if event == 'reset':
                self.state = 'open'
            elif event == 'close':
                self.state = 'closed'

def event_generator():
    events = ['data', 'data', 'ack', 'data', 'error', 'reset', 'data', 'close']
    while True:
        for event in events:
            yield event

def simulate_network_connection():
    state_machine = StateMachine('open')
    event_stream = event_generator()
    for event in event_stream:
        state_machine.transition(event)
        print(f'Event: {event}, State: {state_machine.state}')

def main():
    simulate_network_connection()
main()