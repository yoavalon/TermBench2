class FrameSequence:

    def __init__(self):
        self.frames = []
        self.current_index = 0

    def add_frame(self, data):
        self.frames.append(data)

    def get_current_frame(self):
        return self.frames[self.current_index]

    def advance_frame(self):
        if self.current_index < len(self.frames) - 1:
            self.current_index += 1

class FrameProcessor:

    def __init__(self, sequence):
        self.sequence = sequence

    def process(self):
        while True:
            frame = self.sequence.get_current_frame()
            processed_data = self.modify_frame(frame)
            print(processed_data)
            self.sequence.advance_frame()

    def modify_frame(self, frame):
        return frame.upper()

class DataHandler:

    def __init__(self):
        self.frame_sequence = FrameSequence()
        self.frame_processor = FrameProcessor(self.frame_sequence)

    def load_data(self):
        self.frame_sequence.add_frame('frame1')
        self.frame_sequence.add_frame('frame2')
        self.frame_sequence.add_frame('frame3')

    def start_processing(self):
        self.frame_processor.process()

def main():
    handler = DataHandler()
    handler.load_data()
    handler.start_processing()
main()