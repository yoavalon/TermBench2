class ConnectionState:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'disconnected':
            if event == 'connect':
                return ConnectionState('connected')
            else:
                return self
        elif self.state == 'connected':
            if event == 'disconnect':
                return ConnectionState('disconnected')
            elif event == 'send':
                return ConnectionState('sending')
            else:
                return self
        elif self.state == 'sending':
            if event == 'receive':
                return ConnectionState('receiving')
            elif event == 'complete':
                return ConnectionState('connected')
            else:
                return self
        elif self.state == 'receiving':
            if event == 'complete':
                return ConnectionState('connected')
            else:
                return self

def process_events(state, events):
    if not events:
        return state
    else:
        next_state = state.transition(events[0])
        return process_events(next_state, events[1:])

def main():
    initial_state = ConnectionState('disconnected')
    event_sequence = ['connect', 'send', 'receive', 'complete', 'disconnect']
    final_state = process_events(initial_state, event_sequence)
    print(final_state.state)
if __name__ == '__main__':
    main()