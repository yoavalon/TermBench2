class SignalProcessor:

    def __init__(self, data):
        self.data = data

    def filter(self, threshold):

        def recursive_filter(index):
            if index >= len(self.data):
                return
            if self.data[index] > threshold:
                self.data[index] = 0
            recursive_filter(index + 1)
        recursive_filter(0)

    def amplify(self, factor):

        def recursive_amplify(index):
            if index >= len(self.data):
                return
            self.data[index] *= factor
            recursive_amplify(index + 1)
        recursive_amplify(0)

    def normalize(self, max_value):

        def recursive_normalize(index):
            if index >= len(self.data):
                return
            self.data[index] = self.data[index] / max_value
            recursive_normalize(index + 1)
        recursive_normalize(0)

def main():
    data = [i % 10 for i in range(10000)]
    processor = SignalProcessor(data)
    processor.filter(5)
    processor.amplify(2)
    processor.normalize(20)
    main()
main()