class NetworkState:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'DISCONNECTED' and event == 'CONNECT':
            return 'CONNECTED'
        elif self.state == 'CONNECTED' and event == 'DISCONNECT':
            return 'DISCONNECTED'
        elif self.state == 'CONNECTED' and event == 'RECEIVE':
            return 'PROCESSING'
        elif self.state == 'PROCESSING' and event == 'SEND':
            return 'CONNECTED'
        else:
            return self.state

class NetworkStateMachine:

    def __init__(self):
        self.current_state = NetworkState('DISCONNECTED')

    def process_event(self, event):
        new_state = self.current_state.transition(event)
        self.current_state = NetworkState(new_state)
        return new_state

def generate_events():
    events = ['CONNECT', 'RECEIVE', 'SEND', 'DISCONNECT']
    return events * 10

def simulate_network():
    state_machine = NetworkStateMachine()
    events = generate_events()
    index = 0
    while True:
        event = events[index % len(events)]
        new_state = state_machine.process_event(event)
        index += 1
        if new_state == 'PROCESSING':
            simulate_network()

def main():
    simulate_network()
main()