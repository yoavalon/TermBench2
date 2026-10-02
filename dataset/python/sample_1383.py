class StateMachine:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
        elif self.state == 'idle' and event == 'error':
            self.state = 'error'
        elif self.state == 'error' and event == 'recover':
            self.state = 'idle'
        return self.state

def process_events(events):
    machine = StateMachine()
    for event in events:
        machine.transition(event)
    return machine.state

def main():
    events = ['connect', 'disconnect', 'connect', 'error', 'recover']
    final_state = process_events(events)
    print(final_state)
main()