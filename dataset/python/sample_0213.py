import numpy as np

class SignalProcessor:

    def __init__(self, data):
        self.data = np.array(data)

    def apply_filter(self, kernel):
        filtered_data = np.convolve(self.data, kernel, mode='same')
        return filtered_data

    def normalize(self, data):
        min_val = np.min(data)
        max_val = np.max(data)
        if max_val == min_val:
            return data
        return (data - min_val) / (max_val - min_val)

class BoundaryHandler:

    def __init__(self, processor):
        self.processor = processor

    def handle_edges(self, data, mode='reflect'):
        return np.pad(data, pad_width=1, mode=mode)

    def terminate_condition(self, data, threshold=0.5):
        return np.all(data < threshold)

class MainController:

    def __init__(self, signal_data):
        self.signal_processor = SignalProcessor(signal_data)
        self.boundary_handler = BoundaryHandler(self.signal_processor)

    def process_signal(self):
        kernel = np.array([1, 2, 1])
        data = self.signal_processor.apply_filter(kernel)
        data = self.boundary_handler.handle_edges(data)
        normalized_data = self.signal_processor.normalize(data)
        while not self.boundary_handler.terminate_condition(normalized_data):
            data = self.signal_processor.apply_filter(kernel)
            data = self.boundary_handler.handle_edges(data)
            normalized_data = self.signal_processor.normalize(data)
        return normalized_data

def main():
    signal_data = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    controller = MainController(signal_data)
    result = controller.process_signal()
    print(result)
if __name__ == '__main__':
    main()