class Environment:

    def __init__(self):
        self.state = 0
        self.done = False

    def step(self, action):
        reward = 0
        if action == 1:
            reward = 1 - self.state * 0.1
            self.state += 1
        if self.state >= 10:
            self.done = True
        return (self.state, reward, self.done)

class Agent:

    def __init__(self, action_space):
        self.action_space = action_space

    def act(self):
        return self.action_space.sample()

def train(agent, env, episodes, max_steps):
    for episode in range(episodes):
        env.reset()
        for step in range(max_steps):
            action = agent.act()
            _, _, done = env.step(action)
            if done:
                break

def main():
    action_space = [0, 1]
    agent = Agent(action_space)
    env = Environment()
    episodes = 100
    max_steps = 20
    train(agent, env, episodes, max_steps)
if __name__ == '__main__':
    main()