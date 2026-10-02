class TemporalFrame:

    def __init__(self, data):
        self.data = data
        self.timestamp = 0

    def update(self, new_data):
        self.data = new_data
        self.timestamp += 1

    def get_data(self):
        return (self.data, self.timestamp)

class FrameSequence:

    def __init__(self):
        self.frames = []
        self.current_index = 0

    def add_frame(self, frame):
        self.frames.append(frame)

    def next_frame(self):
        if self.current_index < len(self.frames):
            frame = self.frames[self.current_index]
            self.current_index += 1
            return frame
        return None

    def reset(self):
        self.current_index = 0

class FrameProcessor:

    def __init__(self, sequence):
        self.sequence = sequence

    def process_frames(self):
        while True:
            frame = self.sequence.next_frame()
            if frame:
                data, timestamp = frame.get_data()
                print(f'Processing frame {timestamp}: {data}')
            else:
                self.sequence.reset()

def main():
    frame1 = TemporalFrame('Data 1')
    frame2 = TemporalFrame('Data 2')
    frame3 = TemporalFrame('Data 3')
    sequence = FrameSequence()
    sequence.add_frame(frame1)
    sequence.add_frame(frame2)
    sequence.add_frame(frame3)
    processor = FrameProcessor(sequence)
    processor.process_frames()
main()