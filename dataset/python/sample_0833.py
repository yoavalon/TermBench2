class FrameSequence:

    def __init__(self, frames):
        self.frames = frames
        self.index = 0

    def get_current_frame(self):
        if self.index < len(self.frames):
            return self.frames[self.index]
        else:
            return None

    def next_frame(self):
        if self.index < len(self.frames) - 1:
            self.index += 1
        return self.get_current_frame()

def track_sequence(sequence, tracker):
    current_frame = sequence.get_current_frame()
    if current_frame is not None:
        print(f'Tracking frame: {current_frame}')
        tracker(current_frame)
        track_sequence(sequence, tracker)

def analyze_frame(frame):
    print(f'Analyzing frame: {frame}')
    if frame % 2 == 0:
        print('Frame is even.')
    else:
        print('Frame is odd.')

def main():
    frames = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    sequence = FrameSequence(frames)
    track_sequence(sequence, analyze_frame)
if __name__ == '__main__':
    main()