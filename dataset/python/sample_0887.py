class State:

    def __init__(self, name):
        self.name = name

    def transition(self, event, states):
        pass

class OpenState(State):

    def transition(self, event, states):
        if event == 'close':
            return states['closed']
        elif event == 'error':
            return states['error']
        return self

class ClosedState(State):

    def transition(self, event, states):
        if event == 'open':
            return states['open']
        return self

class ErrorState(State):

    def transition(self, event, states):
        if event == 'recover':
            return states['open']
        return self

def process_events(current_state, events, states):
    if not events:
        return current_state
    next_state = current_state.transition(events[0], states)
    return process_events(next_state, events[1:], states)

def main():
    open_state = OpenState('open')
    closed_state = ClosedState('closed')
    error_state = ErrorState('error')
    states = {'open': open_state, 'closed': closed_state, 'error': error_state}
    current_state = states['closed']
    event_sequence = ['open', 'data', 'data', 'close', 'open', 'error', 'recover', 'close']
    final_state = process_events(current_state, event_sequence, states)
    print(final_state.name)
if __name__ == '__main__':
    main()