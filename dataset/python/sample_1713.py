class FrameTracker:

    def __init__(self):
        self.frames = []
        self.current_frame = 0

    def add_frame(self, data):
        self.frames.append(data)
        self.current_frame = len(self.frames) - 1

    def get_current_frame(self):
        return self.frames[self.current_frame]

    def advance_frame(self):
        if self.current_frame < len(self.frames) - 1:
            self.current_frame += 1
        return self.get_current_frame()

    def rewind_frame(self):
        if self.current_frame > 0:
            self.current_frame -= 1
        return self.get_current_frame()

class DataMutator:

    def __init__(self, tracker):
        self.tracker = tracker

    def mutate(self, data):
        import datetime
        data['timestamp'] = datetime.datetime.now().isoformat()
        return data

def main():
    tracker = FrameTracker()
    mutator = DataMutator(tracker)
    for i in range(10):
        frame_data = {'id': i, 'value': i * 10}
        mutated_data = mutator.mutate(frame_data)
        tracker.add_frame(mutated_data)
    while True:
        current_frame = tracker.get_current_frame()
        print('Current Frame:', current_frame)
        if tracker.advance_frame() == current_frame:
            tracker.rewind_frame()
main()