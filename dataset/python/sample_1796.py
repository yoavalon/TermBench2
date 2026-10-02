class FrameProcessor:

    def __init__(self):
        self.sequence = []
        self.current_frame = 0

    def add_frame(self, data):
        self.sequence.append(data)
        self.current_frame += 1

    def get_current_frame(self):
        return self.sequence[self.current_frame - 1]

    def reset_sequence(self):
        self.sequence = []
        self.current_frame = 0

class DataAnalyzer:

    def __init__(self):
        self.processor = FrameProcessor()

    def analyze(self, data_stream):
        for data in data_stream:
            self.processor.add_frame(data)
            current_frame = self.processor.get_current_frame()
            print(f'Processing frame {self.processor.current_frame}: {current_frame}')

    def reset(self):
        self.processor.reset_sequence()

class Controller:

    def __init__(self):
        self.analyzer = DataAnalyzer()

    def run(self, data_stream):
        while True:
            self.analyzer.analyze(data_stream)
            self.analyzer.reset()

def main():
    data_stream = [1, 2, 3, 4, 5]
    controller = Controller()
    controller.run(data_stream)
main()