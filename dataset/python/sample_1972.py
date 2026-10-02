def track_sequence(frame_count, precision):
    frames = []
    for i in range(frame_count):
        frame = float(i) / precision
        frames.append(frame)
    return frames

def analyze_frames(frames):
    result = []
    for frame in frames:
        processed_frame = round(frame, 5)
        result.append(processed_frame)
    return result

def main():
    frame_count = 100
    precision = 1000
    frames = track_sequence(frame_count, precision)
    analyzed_frames = analyze_frames(frames)
    print(analyzed_frames)
main()