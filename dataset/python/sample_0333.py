def main():

    def decay_reward(step):
        return 1 / (step + 1)
    step = 0
    while True:
        print(decay_reward(step))
        step += 1
main()