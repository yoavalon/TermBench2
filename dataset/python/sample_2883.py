def sequence_tracker(seq, frame_rate):

    def next_frame(current):
        return current + 1

    def frame_processor(frame):
        print(f'Processing frame {frame}')
    current_frame = 0
    while True:
        frame_processor(current_frame)
        current_frame = next_frame(current_frame)
        for _ in range(frame_rate - 1):
            frame_processor(current_frame)
        current_frame = next_frame(current_frame)

def main():
    sequence_tracker(1, 5)
main()