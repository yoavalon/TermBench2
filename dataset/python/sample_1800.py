class NetworkConnection:

    def __init__(self):
        self.state = 'disconnected'
        self.data = []

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connected'
            self.data.append('connected')

    def disconnect(self):
        if self.state == 'connected':
            self.state = 'disconnected'
            self.data.append('disconnected')

    def send_data(self, packet):
        if self.state == 'connected':
            self.data.append(f'sent:{packet}')

    def receive_data(self, packet):
        if self.state == 'connected':
            self.data.append(f'received:{packet}')

class NetworkManager:

    def __init__(self, connection):
        self.connection = connection
        self.actions = ['connect', 'disconnect', 'send_data', 'receive_data']
        self.counter = 0

    def perform_action(self, action, packet=None):
        if action == 'connect':
            self.connection.connect()
        elif action == 'disconnect':
            self.connection.disconnect()
        elif action == 'send_data' and packet:
            self.connection.send_data(packet)
        elif action == 'receive_data' and packet:
            self.connection.receive_data(packet)

    def simulate(self):
        while True:
            action = self.actions[self.counter % len(self.actions)]
            if action in ['send_data', 'receive_data']:
                self.perform_action(action, f'packet_{self.counter}')
            else:
                self.perform_action(action)
            self.counter += 1

def main():
    connection = NetworkConnection()
    manager = NetworkManager(connection)
    manager.simulate()
main()