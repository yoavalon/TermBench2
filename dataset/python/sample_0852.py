class DigitalSignalProcessor:

    def __init__(self, data):
        self.data = data

    def process(self, index=0):
        if index >= len(self.data):
            return []
        else:
            processed_value = self.apply_filter(self.data[index])
            return [processed_value] + self.process(index + 1)

    def apply_filter(self, value):
        return value * 2

class RecursiveAnalysis:

    def __init__(self, processor):
        self.processor = processor

    def analyze(self, index=0):
        if index >= len(self.processor.data):
            return {}
        else:
            result = self.analyze_data(self.processor.data[index])
            return {index: result} | self.analyze(index + 1)

    def analyze_data(self, value):
        return value > 10

class TerminationChecker:

    def __init__(self, data):
        self.data = data

    def check(self, index=0):
        if index >= len(self.data):
            return True
        else:
            return self.check_condition(self.data[index]) and self.check(index + 1)

    def check_condition(self, value):
        return value < 100

def main():
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    dsp = DigitalSignalProcessor(data)
    processor = RecursiveAnalysis(dsp)
    checker = TerminationChecker(data)
    processed_data = dsp.process()
    analysis_results = processor.analyze()
    termination_status = checker.check()
    print(processed_data)
    print(analysis_results)
    print(termination_status)
if __name__ == '__main__':
    main()