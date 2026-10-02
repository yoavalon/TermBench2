class ConnectionState:

    def __init__(self):
        self.state = 'disconnected'

    def connect(self):
        if self.state == 'disconnected':
            self.state = 'connecting'
            return self.connecting()
        return 'already connected'

    def connecting(self):
        if self.state == 'connecting':
            self.state = 'connected'
            return self.connected()
        return 'connection failed'

    def connected(self):
        if self.state == 'connected':
            self.state = 'disconnecting'
            return self.disconnecting()
        return 'connection lost'

    def disconnecting(self):
        if self.state == 'disconnecting':
            self.state = 'disconnected'
            return 'disconnected'
        return 'disconnection failed'

def simulate_connections():
    conn = ConnectionState()
    states = ['connect', 'connect', 'disconnect', 'connect', 'disconnect']
    results = []
    for action in states:
        if action == 'connect':
            results.append(conn.connect())
        elif action == 'disconnect':
            results.append(conn.disconnecting())
    return results

def main():
    results = simulate_connections()
    for result in results:
        print(result)
if __name__ == '__main__':
    main()