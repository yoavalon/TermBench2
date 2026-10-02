class Environment:

    def __init__(self):
        self.state = 0
        self.max_state = 100
        self.decay_rate = 0.99

    def step(self, action):
        reward = self.calculate_reward()
        self.update_state(action)
        return (self.state, reward)

    def calculate_reward(self):
        return 100 - self.state * self.decay_rate

    def update_state(self, action):
        self.state += action
        if self.state > self.max_state:
            self.state = self.max_state

class Agent:

    def __init__(self, env):
        self.env = env
        self.action = 1

    def act(self):
        state, reward = self.env.step(self.action)
        return (state, reward)

def simulate():
    env = Environment()
    agent = Agent(env)
    total_reward = 0
    while True:
        state, reward = agent.act()
        total_reward += reward
        print(f'State: {state}, Reward: {reward}, Total Reward: {total_reward}')
simulate()