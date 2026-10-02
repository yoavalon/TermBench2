class NetworkState:

    def __init__(self):
        self.state = 'DISCONNECTED'
        self.connection_attempts = 0

    def connect(self):
        if self.state == 'DISCONNECTED':
            self.state = 'CONNECTING'
            self.connection_attempts += 1

    def check_status(self):
        if self.state == 'CONNECTING':
            if self.connection_attempts < 3:
                self.state = 'CONNECTED'
            else:
                self.state = 'FAILED'

    def disconnect(self):
        if self.state == 'CONNECTED':
            self.state = 'DISCONNECTING'
            self.connection_attempts = 0

class NetworkManager:

    def __init__(self):
        self.network_state = NetworkState()

    def manage_connection(self):
        while True:
            self.network_state.connect()
            self.network_state.check_status()
            if self.network_state.state == 'FAILED':
                break

def main():
    manager = NetworkManager()
    manager.manage_connection()
main()