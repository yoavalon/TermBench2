def recursive_reward_decay(alpha, gamma, t):
    if t == 0:
        return 1
    else:
        return alpha * gamma ** t + recursive_reward_decay(alpha, gamma, t - 1)

def main():
    alpha = 0.5
    gamma = 0.9
    t = 0
    while True:
        print(recursive_reward_decay(alpha, gamma, t))
        t += 1
main()