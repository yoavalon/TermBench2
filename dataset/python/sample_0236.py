import numpy as np

class Environment:

    def __init__(self, size=10, decay_rate=0.95):
        self.state = np.zeros(size)
        self.decay_rate = decay_rate
        self.action_space = np.arange(size)

    def step(self, action):
        reward = self.state[action]
        self.state[action] *= self.decay_rate
        return (self.state, reward)

class Agent:

    def __init__(self, action_space):
        self.action_space = action_space

    def select_action(self):
        return np.random.choice(self.action_space)

class Simulator:

    def __init__(self, env, agent, max_steps=100):
        self.env = env
        self.agent = agent
        self.max_steps = max_steps

    def run(self):
        for step in range(self.max_steps):
            action = self.agent.select_action()
            state, reward = self.env.step(action)
            if np.sum(state) < 0.01:
                break
        return step + 1

def main():
    env = Environment(size=10, decay_rate=0.95)
    agent = Agent(action_space=env.action_space)
    simulator = Simulator(env, agent, max_steps=100)
    steps_to_terminate = simulator.run()
    print(steps_to_terminate)
if __name__ == '__main__':
    main()