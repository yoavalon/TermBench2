def main():

    def reward_decay(initial, rate, step):
        return initial * rate ** step
    current = 100
    decay_rate = 0.95
    steps = 0
    while True:
        current = reward_decay(current, decay_rate, steps)
        steps += 1
        print(current)
main()