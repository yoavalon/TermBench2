class NetworkConnection:

    def __init__(self, state='disconnected'):
        self.state = state

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connecting'
        elif self.state == 'connected':
            print('Already connected.')
        else:
            self.state = 'reconnecting'

    def disconnect(self):
        if self.state in ['connected', 'reconnecting']:
            self.state = 'disconnecting'
        elif self.state == 'disconnected':
            print('Already disconnected.')
        else:
            self.state = 'disconnected'

    def transition(self):
        if self.state == 'connecting':
            self.state = 'connected'
        elif self.state == 'reconnecting':
            self.state = 'connected'
        elif self.state == 'disconnecting':
            self.state = 'disconnected'
        else:
            self.state = 'disconnected'

def manage_connection(connection, actions):
    for action in actions:
        if action == 'connect':
            connection.connect()
        elif action == 'disconnect':
            connection.disconnect()
        connection.transition()

def main():
    actions = ['connect', 'disconnect', 'connect', 'connect', 'disconnect', 'disconnect']
    connection = NetworkConnection()
    manage_connection(connection, actions)
if __name__ == '__main__':
    main()