class StateMachine:

    def __init__(self):
        self.state = 'idle'
        self.connection = None

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
            self.connection = True
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'
            self.connection = False
        elif self.state == 'connected' and event == 'error':
            self.state = 'error'
            self.connection = False
        elif self.state == 'error' and event == 'recover':
            self.state = 'connected'
            self.connection = True

    def get_status(self):
        return (self.state, self.connection)

def simulate_events(events):
    machine = StateMachine()
    statuses = []
    for event in events:
        machine.transition(event)
        statuses.append(machine.get_status())
    return statuses

def main():
    events_sequence = ['connect', 'data', 'disconnect', 'connect', 'error', 'recover']
    results = simulate_events(events_sequence)
    for status in results:
        print(status)
if __name__ == '__main__':
    main()