class NetworkStateMachine:

    def __init__(self, states, transitions):
        self.states = states
        self.transitions = transitions
        self.current_state = states[0]

    def transition(self, event):
        if (self.current_state, event) in self.transitions:
            self.current_state = self.transitions[self.current_state, event]
        else:
            raise ValueError('Invalid transition')

    def is_terminal(self):
        return self.current_state in ['disconnected', 'error']

class EventManager:

    def __init__(self, events):
        self.events = events
        self.index = 0

    def get_next_event(self):
        if self.index < len(self.events):
            event = self.events[self.index]
            self.index += 1
            return event
        else:
            return None

def main():
    states = ['idle', 'connected', 'disconnected', 'error']
    transitions = {('idle', 'connect'): 'connected', ('connected', 'disconnect'): 'disconnected', ('connected', 'error'): 'error', ('disconnected', 'connect'): 'connected', ('error', 'reset'): 'idle'}
    events = ['connect', 'disconnect', 'error', 'reset', 'connect', 'disconnect', 'connect', 'error', 'reset']
    network_machine = NetworkStateMachine(states, transitions)
    event_manager = EventManager(events)
    while True:
        event = event_manager.get_next_event()
        if event is None or network_machine.is_terminal():
            break
        network_machine.transition(event)
    print(f'Final state: {network_machine.current_state}')
if __name__ == '__main__':
    main()