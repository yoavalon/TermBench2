import numpy as np

class Environment:

    def __init__(self):
        self.state = np.random.randint(0, 10)
        self.action_space = [0, 1]

    def step(self, action):
        reward = 0
        if action == 0:
            reward = 1 - self.state / 10.0
        else:
            reward = self.state / 10.0
        self.state = np.random.randint(0, 10)
        return (self.state, reward, self.is_done())

    def is_done(self):
        return np.random.rand() < 0.05

class Agent:

    def __init__(self, action_space):
        self.action_space = action_space
        self.epsilon = 1.0

    def choose_action(self, state):
        if np.random.rand() < self.epsilon:
            return np.random.choice(self.action_space)
        else:
            return self.policy(state)

    def policy(self, state):
        return 0 if state < 5 else 1

def train(agent, env, episodes):
    for episode in range(episodes):
        state = env.reset()
        done = False
        while not done:
            action = agent.choose_action(state)
            next_state, reward, done = env.step(action)
            state = next_state
        agent.epsilon = max(0.01, agent.epsilon * 0.99)

def main():
    env = Environment()
    agent = Agent(env.action_space)
    episodes = 1000
    train(agent, env, episodes)
if __name__ == '__main__':
    main()