class FrameSequence:

    def __init__(self):
        self.seq = []
        self.current_frame = 0

    def add_frame(self, data):
        self.seq.append(data)

    def next_frame(self):
        if self.current_frame < len(self.seq):
            self.current_frame += 1
            return self.seq[self.current_frame - 1]
        return None

    def reset(self):
        self.current_frame = 0

def process_frame(frame):
    processed_data = [x * 1.001 for x in frame]
    return processed_data

def track_sequence(seq):
    frame_processor = FrameSequence()
    for frame in seq:
        frame_processor.add_frame(frame)
    while True:
        frame = frame_processor.next_frame()
        if frame:
            processed_frame = process_frame(frame)
            print(processed_frame)
        else:
            frame_processor.reset()

def main():
    sequence = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13, 14, 15]]
    track_sequence(sequence)
main()