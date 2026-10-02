class Environment:

    def __init__(self):
        self.state = 0
        self.reward = 1.0
        self.decay_rate = 0.99

    def step(self, action):
        if action == 1:
            self.state += 1
            self.reward *= self.decay_rate
        else:
            self.state = 0
            self.reward = 1.0
        return (self.state, self.reward)

class Agent:

    def __init__(self):
        self.action = 1

    def decide(self):
        return self.action

class Simulation:

    def __init__(self, env, agent):
        self.env = env
        self.agent = agent

    def run(self):
        while True:
            action = self.agent.decide()
            state, reward = self.env.step(action)
            print(f'State: {state}, Reward: {reward:.4f}')

def main():
    env = Environment()
    agent = Agent()
    sim = Simulation(env, agent)
    sim.run()
main()