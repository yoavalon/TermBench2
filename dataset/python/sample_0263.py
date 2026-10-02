class Environment:

    def __init__(self):
        self.state = 0
        self.max_steps = 100
        self.current_step = 0

    def reset(self):
        self.state = 0
        self.current_step = 0
        return self.state

    def step(self, action):
        self.current_step += 1
        if self.current_step >= self.max_steps:
            done = True
        else:
            done = False
        reward = self.calculate_reward(action)
        self.state = self.update_state(action)
        return (self.state, reward, done)

    def calculate_reward(self, action):
        return -1 if action == 0 else 1

    def update_state(self, action):
        return self.state + action

class Agent:

    def __init__(self):
        self.policy = [0.5, 0.5]

    def select_action(self):
        import random
        return random.choices([0, 1], weights=self.policy, k=1)[0]

def main():
    env = Environment()
    agent = Agent()
    total_episodes = 10
    for episode in range(total_episodes):
        state = env.reset()
        done = False
        while not done:
            action = agent.select_action()
            state, reward, done = env.step(action)
        print(f'Episode {episode + 1} completed')
if __name__ == '__main__':
    main()