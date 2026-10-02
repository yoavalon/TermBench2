class NetworkState:

    def __init__(self, state):
        self.state = state

    def transition(self, event):
        if self.state == 'initial':
            if event == 'connect':
                return 'connected'
            elif event == 'timeout':
                return 'failed'
        elif self.state == 'connected':
            if event == 'disconnect':
                return 'disconnected'
            elif event == 'data':
                return 'data_received'
        elif self.state == 'disconnected':
            if event == 'reconnect':
                return 'reconnecting'
        elif self.state == 'failed':
            if event == 'retry':
                return 'reconnecting'
        elif self.state == 'reconnecting':
            if event == 'connect':
                return 'connected'
            elif event == 'timeout':
                return 'failed'
        elif self.state == 'data_received':
            if event == 'process':
                return 'processing'
            elif event == 'disconnect':
                return 'disconnected'
        elif self.state == 'processing':
            if event == 'complete':
                return 'processed'
            elif event == 'error':
                return 'failed'
        elif self.state == 'processed':
            if event == 'end':
                return 'final'
        return self.state

def process_event(state, event):
    return NetworkState(state.transition(event))

def simulate_network():
    states = ['initial', 'connected', 'disconnected', 'failed', 'reconnecting', 'data_received', 'processing', 'processed', 'final']
    events = ['connect', 'disconnect', 'data', 'process', 'complete', 'error', 'retry', 'timeout', 'end']
    current_state = NetworkState('initial')
    for _ in range(10):
        event = events[_ % len(events)]
        current_state = process_event(current_state, event)
        if current_state.state == 'final':
            break

def main():
    simulate_network()
if __name__ == '__main__':
    main()