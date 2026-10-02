class ConnectionState:

    def __init__(self, status='disconnected'):
        self.status = status

    def connect(self):
        if self.status == 'disconnected':
            self.status = 'connected'
            return 'Connection established'
        return 'Already connected'

    def disconnect(self):
        if self.status == 'connected':
            self.status = 'disconnected'
            return 'Connection terminated'
        return 'Already disconnected'

    def toggle(self):
        if self.status == 'connected':
            self.status = 'disconnected'
        else:
            self.status = 'connected'
        return f'Status toggled to {self.status}'

class NetworkHandler:

    def __init__(self):
        self.state = ConnectionState()

    def manage_connection(self):
        while True:
            action = self.decide_action()
            if action == 'connect':
                self.state.connect()
            elif action == 'disconnect':
                self.state.disconnect()
            elif action == 'toggle':
                self.state.toggle()
            else:
                break

    def decide_action(self):
        if self.state.status == 'connected':
            return 'disconnect'
        else:
            return 'connect'

def main():
    handler = NetworkHandler()
    handler.manage_connection()
main()