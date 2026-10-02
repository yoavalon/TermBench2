class Environment:

    def __init__(self):
        self.state = 0
        self.rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

    def reset(self):
        self.state = 0
        return self.state

    def step(self, action):
        if action == 0:
            reward = self.rewards[self.state]
            self.state = min(self.state + 1, len(self.rewards) - 1)
            done = False
        else:
            reward = 0
            done = True
        return (self.state, reward, done)

class Agent:

    def __init__(self):
        self.policy = [0.9, 0.1]

    def select_action(self, state):
        return 0 if state < 5 else 1

def simulate(env, agent):
    env.reset()
    total_reward = 0
    steps = 0
    while True:
        action = agent.select_action(env.state)
        next_state, reward, done = env.step(action)
        total_reward += reward
        steps += 1
        if done:
            env.reset()
        if steps % 100 == 0:
            print(f'Step: {steps}, Total Reward: {total_reward}')

def main():
    env = Environment()
    agent = Agent()
    simulate(env, agent)
main()