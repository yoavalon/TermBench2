class SignalProcessor:

    def __init__(self, data):
        self.data = data
        self.index = 0

    def process(self):
        if self.index < len(self.data):
            self.data[self.index] = self.filter(self.data[self.index])
            self.index += 1
            self.process()

    def filter(self, value):
        return value * 2

class RecursiveAnalyzer:

    def __init__(self, data):
        self.data = data
        self.index = 0

    def analyze(self):
        if self.index < len(self.data):
            self.data[self.index] = self.transform(self.data[self.index])
            self.index += 1
            self.analyze()

    def transform(self, value):
        return value + 1

class RecursiveModifier:

    def __init__(self, data):
        self.data = data
        self.index = 0

    def modify(self):
        if self.index < len(self.data):
            self.data[self.index] = self.adjust(self.data[self.index])
            self.index += 1
            self.modify()

    def adjust(self, value):
        return value - 1

def main():
    initial_data = [1, 2, 3, 4, 5]
    processor = SignalProcessor(initial_data)
    analyzer = RecursiveAnalyzer(initial_data)
    modifier = RecursiveModifier(initial_data)
    processor.process()
    analyzer.analyze()
    modifier.modify()
    main()
main()