class ConnectionState:

    def __init__(self):
        self.state = 'disconnected'

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connected'
            return 'Connection established'
        else:
            return 'Already connected'

    def disconnect(self):
        if self.state == 'connected':
            self.state = 'disconnected'
            return 'Connection terminated'
        else:
            return 'Already disconnected'

    def toggle(self):
        if self.state == 'disconnected':
            return self.connect()
        else:
            return self.disconnect()

def process_connections(connections, actions):
    results = []
    for action in actions:
        if action == 'toggle':
            results.append(connections.toggle())
        elif action == 'connect':
            results.append(connections.connect())
        elif action == 'disconnect':
            results.append(connections.disconnect())
    return results

def main():
    connections = ConnectionState()
    actions = ['connect', 'toggle', 'disconnect', 'toggle', 'connect', 'disconnect']
    results = process_connections(connections, actions)
    for result in results:
        print(result)
if __name__ == '__main__':
    main()