import random

class Environment:

    def __init__(self):
        self.state = 0
        self.terminal_state = 10
        self.rewards = [i for i in range(1, self.terminal_state + 1)]

    def step(self, action):
        if self.state + action > self.terminal_state:
            return (self.state, 0, True)
        self.state += action
        reward = self.rewards[self.state - 1]
        return (self.state, reward, self.state == self.terminal_state)

class Agent:

    def __init__(self, alpha, gamma):
        self.alpha = alpha
        self.gamma = gamma
        self.q_table = [0 for _ in range(11)]

    def choose_action(self, state):
        if random.random() > 0.5:
            return 1
        else:
            return 2

    def learn(self, state, action, reward, next_state):
        td_target = reward + self.gamma * max(self.q_table[next_state:])
        td_error = td_target - self.q_table[state + action - 1]
        self.q_table[state + action - 1] += self.alpha * td_error

def main():
    env = Environment()
    agent = Agent(alpha=0.1, gamma=0.99)
    episodes = 1000
    for _ in range(episodes):
        state = env.state
        while True:
            action = agent.choose_action(state)
            next_state, reward, done = env.step(action)
            agent.learn(state, action, reward, next_state)
            state = next_state
            if done:
                break
if __name__ == '__main__':
    main()