import random

def generate_reward():
    return random.uniform(0.1, 1.0)

def update_state(state, reward, decay_rate):
    return state * decay_rate + reward

def should_terminate(state, threshold):
    return state < threshold

def main():
    state = 1.0
    decay_rate = 0.9
    threshold = 0.1
    steps = 0
    max_steps = 100
    while steps < max_steps and (not should_terminate(state, threshold)):
        reward = generate_reward()
        state = update_state(state, reward, decay_rate)
        steps += 1
    print(f'Terminated after {steps} steps with state {state:.2f}')
main()