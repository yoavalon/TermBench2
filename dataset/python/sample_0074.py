def process_sequence(data):
    frame = 0
    max_frames = 10
    while frame < max_frames:
        process_frame(data, frame)
        frame += 1
    finalize_sequence(data)

def process_frame(data, frame):
    pass

def finalize_sequence(data):
    pass
process_sequence([])