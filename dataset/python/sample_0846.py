class StateMachine:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'idle':
            if event == 'connect':
                self.state = 'connected'
            elif event == 'disconnect':
                self.state = 'disconnected'
        elif self.state == 'connected':
            if event == 'data':
                self.state = 'data_received'
            elif event == 'disconnect':
                self.state = 'disconnected'
        elif self.state == 'data_received':
            if event == 'ack':
                self.state = 'idle'
            elif event == 'disconnect':
                self.state = 'disconnected'
        elif self.state == 'disconnected':
            if event == 'connect':
                self.state = 'connected'

    def get_state(self):
        return self.state

def simulate_network_events(sm, events):
    for event in events:
        sm.transition(event)

def check_termination(sm, target_state, max_steps):
    steps = 0
    while sm.get_state() != target_state and steps < max_steps:
        sm.transition('data')
        steps += 1
    return sm.get_state() == target_state

def main():
    sm = StateMachine('idle')
    events = ['connect', 'data', 'ack', 'disconnect']
    simulate_network_events(sm, events)
    terminated = check_termination(sm, 'idle', 10)
    print(terminated)
if __name__ == '__main__':
    main()