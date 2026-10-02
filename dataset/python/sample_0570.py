class NetworkConnection:

    def __init__(self):
        self.state = 'disconnected'
        self.buffer = []

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connected'
            self.buffer.append('Connection established')

    def disconnect(self):
        if self.state == 'connected':
            self.state = 'disconnected'
            self.buffer.append('Connection terminated')

    def send_data(self, data):
        if self.state == 'connected':
            self.buffer.append(f'Sent: {data}')

    def receive_data(self):
        if self.state == 'connected':
            if self.buffer:
                return self.buffer.pop(0)
            else:
                return 'No data'

class NetworkMonitor:

    def __init__(self, connection):
        self.connection = connection

    def observe(self):
        while True:
            if self.connection.state == 'connected':
                data = self.connection.receive_data()
                if data:
                    print(data)
            else:
                print('Connection lost')

def main():
    connection = NetworkConnection()
    monitor = NetworkMonitor(connection)
    connection.connect()
    connection.send_data('Hello, world!')
    connection.send_data('How are you?')
    monitor.observe()
main()