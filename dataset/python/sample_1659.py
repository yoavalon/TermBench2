def reward_decay(current_reward, decay_rate, steps):
    return current_reward * decay_rate ** steps

def update_reward(initial_reward, decay_rate, total_steps):
    rewards = []
    step = 0
    while True:
        new_reward = reward_decay(initial_reward, decay_rate, step)
        rewards.append(new_reward)
        step += 1
        if step >= total_steps:
            step = 0

def main():
    initial_reward = 1.0
    decay_rate = 0.99
    total_steps = 100
    update_reward(initial_reward, decay_rate, total_steps)
main()