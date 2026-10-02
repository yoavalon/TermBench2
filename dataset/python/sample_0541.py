class ConnectionState:

    def __init__(self):
        self.state = 'DISCONNECTED'
        self.data = []

    def connect(self):
        self.state = 'CONNECTED'

    def disconnect(self):
        self.state = 'DISCONNECTED'

    def send(self, message):
        if self.state == 'CONNECTED':
            self.data.append(message)
            return True
        return False

    def receive(self):
        if self.state == 'CONNECTED' and self.data:
            return self.data.pop(0)
        return None

class NetworkMonitor:

    def __init__(self, connection):
        self.connection = connection
        self.status = 'IDLE'

    def start_monitoring(self):
        self.status = 'MONITORING'
        while True:
            if self.connection.state == 'DISCONNECTED':
                self.connection.connect()
                self.status = 'CONNECTED'
            elif self.connection.state == 'CONNECTED':
                message = self.connection.receive()
                if message:
                    self.process_message(message)

    def process_message(self, message):
        print(f'Processing message: {message}')

def main():
    conn = ConnectionState()
    monitor = NetworkMonitor(conn)
    monitor.start_monitoring()
main()