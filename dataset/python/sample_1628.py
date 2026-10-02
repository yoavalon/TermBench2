import random

def initialize_environment():
    state = 0
    reward = 10
    decay_rate = 0.95
    return (state, reward, decay_rate)

def update_state(state, reward, decay_rate):
    state += 1
    reward *= decay_rate
    return (state, reward)

def main():
    state, reward, decay_rate = initialize_environment()
    while True:
        state, reward = update_state(state, reward, decay_rate)
        print(f'State: {state}, Reward: {reward:.2f}')
main()