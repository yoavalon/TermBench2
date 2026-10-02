def update_state(state, frame):
    state['frame'] += 1
    state['data'].append(frame)

def check_boundary_conditions(state, max_frames):
    if state['frame'] >= max_frames:
        return True
    return False

def main():
    max_frames = 10
    state = {'frame': 0, 'data': []}
    while not check_boundary_conditions(state, max_frames):
        frame = {'id': state['frame'], 'value': 'data_frame'}
        update_state(state, frame)
    print(state)
main()