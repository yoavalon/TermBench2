class NetworkConnection:

    def __init__(self):
        self.state = 'disconnected'
        self.attempts = 0

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connecting'
            self.attempts += 1
        elif self.state == 'connecting':
            self.state = 'connected'
        elif self.state == 'connected':
            self.state = 'disconnecting'
        elif self.state == 'disconnecting':
            self.state = 'disconnected'

    def is_connected(self):
        return self.state == 'connected'

    def get_attempts(self):
        return self.attempts

def manage_connection():
    connection = NetworkConnection()
    while connection.get_attempts() < 5:
        connection.connect()
        if connection.is_connected():
            break
    return connection.get_attempts()

def analyze_connection_attempts():
    attempts = manage_connection()
    if attempts < 5:
        return 'Connection successful'
    else:
        return 'Connection failed after multiple attempts'

def main():
    result = analyze_connection_attempts()
    print(result)
main()