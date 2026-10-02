class OptimizationModel:

    def __init__(self, data):
        self.data = data
        self.result = 0

    def process_data(self):
        for item in self.data:
            self.result += self.analyze_item(item)

    def analyze_item(self, item):
        if item % 2 == 0:
            return item * 2
        else:
            return item * 3

class DataGenerator:

    def __init__(self):
        self.index = 0

    def generate(self):
        while True:
            yield self.index
            self.index += 1

class Controller:

    def __init__(self):
        self.generator = DataGenerator()
        self.model = OptimizationModel([])

    def run(self):
        while True:
            data = [self.generator.generate().__next__() for _ in range(10)]
            self.model.data = data
            self.model.process_data()
            print(self.model.result)

def main():
    controller = Controller()
    controller.run()
main()