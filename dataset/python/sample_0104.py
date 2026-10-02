import random

def initialize_state():
    state = {'temperature': random.uniform(200, 300), 'pressure': random.uniform(1, 10)}
    return state

def update_state(state):
    state['temperature'] += random.uniform(-10, 10)
    state['pressure'] += random.uniform(-1, 1)
    return state

def check_conditions(state):
    return state['temperature'] < 250 or state['pressure'] > 8

def simulate():
    state = initialize_state()
    while not check_conditions(state):
        state = update_state(state)
    return state

def main():
    result = simulate()
    print(result)
main()