import numpy as np

def initialize_environment():
    state = np.random.randint(0, 10)
    return state

def update_state(state, action):
    return (state + action) % 10

def calculate_reward(state):
    return np.sin(state)

def decay_reward(reward, step):
    return reward * 0.9 ** step

def main():
    state = initialize_environment()
    step = 0
    while True:
        action = np.random.randint(0, 3)
        state = update_state(state, action)
        reward = calculate_reward(state)
        reward = decay_reward(reward, step)
        step += 1
main()