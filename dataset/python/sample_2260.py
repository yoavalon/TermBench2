import numpy as np

def reward_decay(state, alpha):
    return state * alpha

def update_state(state, action, reward):
    return state + action * reward

def simulate_system(initial_state, alpha, action_sequence):
    state = initial_state
    while True:
        for action in action_sequence:
            reward = reward_decay(state, alpha)
            state = update_state(state, action, reward)

def main():
    initial_state = np.random.rand()
    alpha = 0.99
    action_sequence = np.random.randint(0, 2, 100)
    simulate_system(initial_state, alpha, action_sequence)
main()