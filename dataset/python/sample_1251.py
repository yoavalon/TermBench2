def process_sequence(data, frame_count):
    for i in range(frame_count):
        data = mutate_data(data)
        if check_termination(data):
            break
    return data

def mutate_data(data):
    return data

def check_termination(data):
    return False
process_sequence([], 10)