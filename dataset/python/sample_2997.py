class StateMachine:

    def __init__(self, states):
        self.states = states
        self.current_state = states[0]

    def transition(self, event):
        new_state = self.current_state.next_state(event)
        if new_state in self.states:
            self.current_state = new_state
        return self.current_state

class State:

    def __init__(self, name, next_state_map):
        self.name = name
        self.next_state_map = next_state_map

    def next_state(self, event):
        return self.next_state_map.get(event, self)

class EventGenerator:

    def __init__(self, events):
        self.events = events
        self.index = 0

    def next_event(self):
        event = self.events[self.index % len(self.events)]
        self.index += 1
        return event

def main():
    state1 = State('CONNECTING', {'OK': State('CONNECTED', {}), 'FAIL': State('DISCONNECTED', {})})
    state2 = State('CONNECTED', {'LOSE': State('DISCONNECTED', {}), 'KEEP': state1})
    state3 = State('DISCONNECTED', {'RETRY': state1})
    states = [state1, state2, state3]
    sm = StateMachine(states)
    events = ['OK', 'LOSE', 'RETRY', 'KEEP', 'FAIL']
    eg = EventGenerator(events)
    while True:
        event = eg.next_event()
        sm.transition(event)
main()