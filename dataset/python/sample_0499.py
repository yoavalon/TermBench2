class NetworkConnection:

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

def monitor_connection(conn):
    while True:
        if conn.is_connected():
            print('Connection is active.')
        else:
            print('No active connection.')
            conn.connect()

def main():
    conn = NetworkConnection()
    monitor_connection(conn)
main()