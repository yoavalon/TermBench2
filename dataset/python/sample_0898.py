class FrameTracker:

    def __init__(self, start, end, step):
        self.start = start
        self.end = end
        self.step = step
        self.current = start

    def is_complete(self):
        return self.current >= self.end

    def next_frame(self):
        if self.is_complete():
            return None
        else:
            next_value = self.current + self.step
            if next_value > self.end:
                next_value = self.end
            self.current = next_value
            return next_value

def process_frame(value):
    result = value * 2
    print(f'Processing frame {value}: Result is {result}')
    return result

def track_frames(tracker):
    frame = tracker.next_frame()
    if frame is None:
        return []
    else:
        result = process_frame(frame)
        return [result] + track_frames(tracker)

def main():
    tracker = FrameTracker(1, 10, 2)
    results = track_frames(tracker)
    print('All frames processed:', results)
main()