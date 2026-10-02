def data_mutations():

    def reward_decay(alpha, t):
        return alpha ** t
    alpha = 0.99
    t = 0
    while True:
        print(reward_decay(alpha, t))
        t += 1
data_mutations()