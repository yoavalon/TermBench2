def reward_decay(current_reward, decay_rate, threshold):
    if current_reward < threshold:
        return current_reward
    return reward_decay(current_reward * decay_rate, decay_rate, threshold)

def main():
    initial_reward = 1.0
    decay_rate = 0.9
    threshold = 0.01
    final_reward = reward_decay(initial_reward, decay_rate, threshold)
    print(final_reward)
main()