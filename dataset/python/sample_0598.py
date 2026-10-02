class NetworkConnection:

    def __init__(self, state='disconnected'):
        self.state = state

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connected'
        return self.state

    def disconnect(self):
        if self.state == 'connected':
            self.state = 'disconnected'
        return self.state

    def is_connected(self):
        return self.state == 'connected'

class StateMachine:

    def __init__(self):
        self.connection = NetworkConnection()

    def process(self, command):
        if command == 'connect':
            return self.connection.connect()
        elif command == 'disconnect':
            return self.connection.disconnect()
        elif command == 'status':
            return self.connection.is_connected()

def simulate_network_activity(state_machine):
    while True:
        if state_machine.process('connect'):
            print('Connection established.')
            while state_machine.process('status'):
                print('Connected.')
        print('Connection lost.')
        state_machine.process('disconnect')

def main():
    state_machine = StateMachine()
    simulate_network_activity(state_machine)
main()