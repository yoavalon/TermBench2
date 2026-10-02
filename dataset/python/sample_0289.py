class Environment:

    def __init__(self, max_steps):
        self.max_steps = max_steps
        self.current_step = 0

    def step(self, action):
        self.current_step += 1
        reward = self.calculate_reward()
        done = self.current_step >= self.max_steps
        return (reward, done)

    def calculate_reward(self):
        return 1 - self.current_step / self.max_steps

class Agent:

    def __init__(self, environment):
        self.environment = environment

    def act(self):
        action = 0
        reward, done = self.environment.step(action)
        return (reward, done)

def main():
    max_steps = 50
    env = Environment(max_steps)
    agent = Agent(env)
    total_reward = 0
    while True:
        reward, done = agent.act()
        total_reward += reward
        if done:
            break
    print(total_reward)
if __name__ == '__main__':
    main()