class NetworkState:

    def __init__(self):
        self.status = 'disconnected'
        self.connection_attempts = 0

    def connect(self):
        self.connection_attempts += 1
        if self.connection_attempts < 5:
            self.status = 'connecting'
            self.transition()
        else:
            self.status = 'failed'

    def transition(self):
        if self.status == 'connecting':
            self.status = 'connected'
        elif self.status == 'connected':
            self.status = 'disconnecting'
        elif self.status == 'disconnecting':
            self.status = 'disconnected'
            self.connection_attempts = 0

    def check_status(self):
        return self.status

def state_manager(state):
    while True:
        if state.check_status() == 'disconnected':
            state.connect()
        elif state.check_status() == 'connecting':
            state.transition()
        elif state.check_status() == 'connected':
            state.transition()
        elif state.check_status() == 'disconnecting':
            state.transition()
        elif state.check_status() == 'failed':
            break

def main():
    network_state = NetworkState()
    state_manager(network_state)
main()