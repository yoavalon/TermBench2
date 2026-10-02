def boundary_conditions(state, reward, decay_rate):
    reward *= decay_rate
    if reward < 0.1:
        return 0
    return reward

def main():
    state = 1
    reward = 1.0
    decay_rate = 0.9
    for _ in range(10):
        reward = boundary_conditions(state, reward, decay_rate)
        print(reward)
main()