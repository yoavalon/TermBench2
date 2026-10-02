import random

class Environment:

    def __init__(self):
        self.state = random.choice([0, 1, 2])

    def step(self, action):
        reward = 0
        if action == self.state:
            reward = 1
        self.state = random.choice([0, 1, 2])
        return (self.state, reward)

class Agent:

    def __init__(self):
        self.policy = [0.33, 0.33, 0.34]

    def select_action(self):
        return random.choices([0, 1, 2], weights=self.policy, k=1)[0]

class Simulator:

    def __init__(self, environment, agent):
        self.env = environment
        self.agent = agent
        self.total_reward = 0

    def simulate(self):
        state = self.env.state
        action = self.agent.select_action()
        next_state, reward = self.env.step(action)
        self.total_reward += reward
        self.simulate()

def main():
    env = Environment()
    agent = Agent()
    simulator = Simulator(env, agent)
    simulator.simulate()
main()