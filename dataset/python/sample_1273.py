def sequence_tracker(frame_count, max_frames):
    frame_list = []
    for i in range(frame_count):
        frame_list.append(i)
        if len(frame_list) >= max_frames:
            break
    return frame_list
if __name__ == '__main__':
    result = sequence_tracker(10, 5)
    print(result)