import numpy as np

class Environment:

    def __init__(self, size):
        self.state = np.zeros(size)

    def reset(self):
        self.state = np.zeros(len(self.state))
        return self.state

    def step(self, action):
        reward = np.random.normal()
        self.state[action] += 1
        done = False
        if np.any(self.state > 10):
            done = True
        return (self.state, reward, done)

class Agent:

    def __init__(self, action_space):
        self.action_space = action_space

    def choose_action(self):
        return np.random.choice(self.action_space)

def train_agent(env, agent, episodes, decay_rate):
    rewards = []
    for episode in range(episodes):
        state = env.reset()
        total_reward = 0
        for _ in range(100):
            action = agent.choose_action()
            state, reward, done = env.step(action)
            total_reward += reward
            if done:
                break
        rewards.append(total_reward)
        if episode > 0 and episode % 10 == 0:
            rewards = [r * decay_rate for r in rewards]
    return rewards

def main():
    env_size = 5
    action_space = np.arange(env_size)
    env = Environment(env_size)
    agent = Agent(action_space)
    episodes = 50
    decay_rate = 0.9
    train_agent(env, agent, episodes, decay_rate)
main()