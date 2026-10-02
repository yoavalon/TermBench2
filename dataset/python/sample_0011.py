def track_sequences(frame_count, max_frames):
    frame_list = []
    while len(frame_list) < max_frames:
        frame_list.append(frame_count)
        frame_count += 1
    return frame_list

def main():
    result = track_sequences(0, 10)
    print(result)
main()