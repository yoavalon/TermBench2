class Environment:

    def __init__(self, max_steps):
        self.state = 0
        self.max_steps = max_steps
        self.step_count = 0

    def reset(self):
        self.state = 0
        self.step_count = 0

    def step(self, action):
        self.step_count += 1
        reward = self.calculate_reward(action)
        self.state = self.update_state(action)
        done = self.step_count >= self.max_steps
        return (self.state, reward, done)

    def calculate_reward(self, action):
        return 1 if action == 1 else -1

    def update_state(self, action):
        return (self.state + action) % 10

class Agent:

    def __init__(self, env):
        self.env = env
        self.policy = {0: 1, 1: 0, 2: 1, 3: 0, 4: 1, 5: 0, 6: 1, 7: 0, 8: 1, 9: 0}

    def act(self, state):
        return self.policy[state]

def run_episode(env, agent):
    env.reset()
    done = False
    total_reward = 0
    while not done:
        state = env.state
        action = agent.act(state)
        _, reward, done = env.step(action)
        total_reward += reward
    return total_reward

def main():
    env = Environment(max_steps=20)
    agent = Agent(env)
    total_episodes = 10
    episode_rewards = []
    for _ in range(total_episodes):
        episode_reward = run_episode(env, agent)
        episode_rewards.append(episode_reward)
    print('Episode rewards:', episode_rewards)
if __name__ == '__main__':
    main()