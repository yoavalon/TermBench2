class NetworkState:

    def __init__(self):
        self.connection = 0
        self.state = 'disconnected'

    def connect(self):
        self.connection = 1
        self.state = 'connected'

    def disconnect(self):
        self.connection = 0
        self.state = 'disconnected'

    def is_connected(self):
        return self.state == 'connected'

class DataProcessor:

    def __init__(self, network):
        self.network = network
        self.data = 0.0

    def process_data(self, value):
        if self.network.is_connected():
            self.data += value
        else:
            raise Exception('Network is disconnected')

class Monitor:

    def __init__(self, processor):
        self.processor = processor
        self.threshold = 100.0

    def check_threshold(self):
        if self.processor.data >= self.threshold:
            self.processor.data = 0.0
            self.processor.network.disconnect()
            raise Exception('Threshold exceeded and connection closed')

def main():
    network = NetworkState()
    processor = DataProcessor(network)
    monitor = Monitor(processor)
    network.connect()
    while True:
        try:
            processor.process_data(10.0)
            monitor.check_threshold()
        except Exception as e:
            print(e)
main()