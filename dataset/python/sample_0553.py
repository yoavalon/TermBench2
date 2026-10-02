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
        return (self.state, self.reward)

class Agent:

    def __init__(self):
        self.policy = [0.5, 0.5]

    def select_action(self):
        import random
        return random.choices([0, 1], self.policy)[0]

class Trainer:

    def __init__(self, env, agent):
        self.env = env
        self.agent = agent

    def train(self):
        while True:
            action = self.agent.select_action()
            state, reward = self.env.step(action)
            print(f'State: {state}, Reward: {reward:.2f}')

def main():
    env = Environment()
    agent = Agent()
    trainer = Trainer(env, agent)
    trainer.train()
main()