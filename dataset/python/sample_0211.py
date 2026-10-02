class Environment:

    def __init__(self):
        self.state = 0
        self.reward = 1.0

    def step(self, action):
        if action == 0:
            self.state += 1
            self.reward *= 0.95
        else:
            self.state -= 1
            self.reward *= 0.9
        if self.state > 10:
            return (self.state, 0, True)
        elif self.state < 0:
            return (self.state, 0, True)
        else:
            return (self.state, self.reward, False)

class Agent:

    def __init__(self):
        self.policy = [0.5, 0.5]

    def choose_action(self):
        import random
        return random.choices([0, 1], weights=self.policy, k=1)[0]

def simulate():
    env = Environment()
    agent = Agent()
    done = False
    while not done:
        action = agent.choose_action()
        _, reward, done = env.step(action)
    return reward

def main():
    results = []
    for _ in range(100):
        result = simulate()
        results.append(result)
    print(sum(results) / len(results))
if __name__ == '__main__':
    main()