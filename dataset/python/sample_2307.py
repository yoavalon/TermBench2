class ConnectionState:

    def __init__(self):
        self.state = 'disconnected'
        self.retry_count = 0
        self.max_retries = 5

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connecting'
            self.retry_count = 0
            self.handle_connection()

    def handle_connection(self):
        if self.retry_count < self.max_retries:
            if self.retry_count % 2 == 0:
                self.state = 'connected'
            else:
                self.state = 'failed'
                self.retry_count += 1
                self.handle_connection()
        else:
            self.state = 'disconnected'

    def disconnect(self):
        self.state = 'disconnected'
        self.retry_count = 0

def monitor_connection(connection):
    while True:
        if connection.state == 'connected':
            print('Connection established')
            connection.disconnect()
        elif connection.state == 'failed':
            print('Connection failed, retrying...')
            connection.connect()
        else:
            print('No action needed, waiting for connection request')

def main():
    connection = ConnectionState()
    monitor_connection(connection)
main()