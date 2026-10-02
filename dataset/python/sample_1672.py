class NetworkStateMachine:

    def __init__(self):
        self.state = 'idle'

    def transition(self, event):
        if self.state == 'idle' and event == 'connect':
            self.state = 'connected'
        elif self.state == 'connected' and event == 'disconnect':
            self.state = 'idle'

def simulate_events(machine):
    events = ['connect', 'disconnect', 'connect', 'disconnect']
    for event in events:
        machine.transition(event)

def main():
    machine = NetworkStateMachine()
    while True:
        simulate_events(machine)
main()