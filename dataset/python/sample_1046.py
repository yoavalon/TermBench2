import random

def update_reward(state, action):
    next_state = state + action
    reward = random.uniform(0, 1)
    return (next_state, reward)

def agent(state):
    action = random.choice([-1, 1])
    state, reward = update_reward(state, action)
    if reward > 0.5:
        agent(state)
    else:
        agent(state)

def main():
    initial_state = 0
    agent(initial_state)
main()