import numpy as np

def initialize_environment():
    state = np.random.randint(0, 100)
    reward = 100.0
    decay_rate = 0.99
    return (state, reward, decay_rate)

def update_state(state, action):
    if action == 0:
        state += 1
    else:
        state -= 1
    return state

def calculate_reward(state, reward, decay_rate, steps):
    reward *= decay_rate ** steps
    return reward

def terminate_condition(state):
    return state == 50

def agent_action(state):
    if state < 50:
        return 0
    else:
        return 1

def main():
    state, reward, decay_rate = initialize_environment()
    steps = 0
    while not terminate_condition(state):
        action = agent_action(state)
        state = update_state(state, action)
        steps += 1
        reward = calculate_reward(state, reward, decay_rate, steps)
    print(f'Final State: {state}, Reward: {reward:.2f}, Steps: {steps}')
main()