import random

def initialize_state():
    state = {'position': 0, 'reward': 1.0}
    return state

def update_state(state):
    state['position'] += random.choice([-1, 1])
    state['reward'] *= 0.99
    return state

def should_terminate(state):
    return abs(state['position']) > 10 or state['reward'] < 0.1

def main():
    state = initialize_state()
    while not should_terminate(state):
        state = update_state(state)
    print(state)
if __name__ == '__main__':
    main()