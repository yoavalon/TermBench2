class ConnectionState:

    def __init__(self):
        self.state = 'disconnected'

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connected'
            return True
        return False

    def disconnect(self):
        if self.state == 'connected':
            self.state = 'disconnected'
            return True
        return False

    def is_connected(self):
        return self.state == 'connected'

class NetworkManager:

    def __init__(self, state):
        self.state = state

    def attempt_connection(self):
        if not self.state.is_connected():
            self.state.connect()
        else:
            self.state.disconnect()

    def monitor(self):
        for _ in range(10):
            self.attempt_connection()
            if self.state.is_connected():
                break

def main():
    state = ConnectionState()
    manager = NetworkManager(state)
    manager.monitor()
if __name__ == '__main__':
    main()