import random

def initialize():
    state = 0
    reward = 1.0
    return (state, reward)

def update(state, reward):
    next_state = state + 1
    if next_state >= 10:
        reward = 0.0
    else:
        reward *= 0.95
    return (next_state, reward)

def check_termination(state):
    return state >= 10

def main():
    state, reward = initialize()
    while not check_termination(state):
        state, reward = update(state, reward)
        print(f'State: {state}, Reward: {reward}')
main()