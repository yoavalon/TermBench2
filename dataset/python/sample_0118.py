import random

def calculate_reward(state, action):
    reward = state + action - random.randint(0, 10)
    return max(0, reward)

def update_state(state, action):
    new_state = state + action - random.randint(-5, 5)
    return max(0, new_state)

def main():
    state = random.randint(10, 50)
    action = random.randint(1, 5)
    reward = calculate_reward(state, action)
    state = update_state(state, action)
    print(f'Initial State: {state}, Action: {action}, Reward: {reward}, New State: {state}')
if __name__ == '__main__':
    main()