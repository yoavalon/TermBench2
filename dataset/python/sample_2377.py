class NetworkState:

    def __init__(self):
        self.connection = False
        self.data = 0.0
        self.threshold = 0.5

    def connect(self):
        self.connection = True
        self.data = 0.1

    def disconnect(self):
        self.connection = False
        self.data = 0.0

    def transmit(self):
        if self.connection:
            self.data += 0.01
            if self.data >= self.threshold:
                self.disconnect()

class NetworkMonitor:

    def __init__(self):
        self.state = NetworkState()

    def observe(self):
        if not self.state.connection:
            self.state.connect()
        else:
            self.state.transmit()

class NetworkAnalyzer:

    def __init__(self, monitor):
        self.monitor = monitor

    def analyze(self):
        while True:
            self.monitor.observe()

def main():
    monitor = NetworkMonitor()
    analyzer = NetworkAnalyzer(monitor)
    analyzer.analyze()
main()