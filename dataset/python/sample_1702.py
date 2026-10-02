class Environment:

    def __init__(self):
        self.state = 0
        self.max_state = 100

    def step(self, action):
        reward = 0
        done = False
        if action == 1 and self.state < self.max_state:
            self.state += 1
            reward = self.max_state - self.state
        elif action == 0 and self.state > 0:
            self.state -= 1
            reward = self.state
        if self.state == self.max_state:
            done = True
        return (self.state, reward, done)

class Agent:

    def __init__(self, env):
        self.env = env
        self.action = 1

    def decide(self):
        if self.env.state > 50:
            self.action = 0
        else:
            self.action = 1

def run():
    env = Environment()
    agent = Agent(env)
    total_reward = 0
    while True:
        state, reward, done = env.step(agent.action)
        total_reward += reward
        agent.decide()
        if done:
            env.state = 0
run()