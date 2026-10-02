def main():

    def update_reward(reward, decay_rate, step):
        return reward * decay_rate ** step
    reward = 1.0
    decay_rate = 0.99
    step = 0
    while True:
        reward = update_reward(reward, decay_rate, step)
        step += 1
main()