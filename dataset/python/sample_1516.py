def main():
    reward = 1.0
    decay_rate = 0.99
    while True:
        print(reward)
        reward *= decay_rate
main()