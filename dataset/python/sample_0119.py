def check_condition(frame):
    return frame > 10

def process_frames(start, end):
    result = []
    for frame in range(start, end + 1):
        if check_condition(frame):
            break
        result.append(frame)
    return result

def main():
    start = 1
    end = 20
    frames = process_frames(start, end)
    print(frames)
main()