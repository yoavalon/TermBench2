class Environment:

    def __init__(self, start, goal, decay_rate):
        self.current = start
        self.goal = goal
        self.decay_rate = decay_rate
        self.time_step = 0

    def step(self, action):
        self.current += action
        self.time_step += 1
        reward = self.compute_reward()
        done = self.is_done()
        return (self.current, reward, done)

    def compute_reward(self):
        distance = abs(self.current - self.goal)
        reward = 1 / (distance + 1)
        reward *= (1 - self.decay_rate) ** self.time_step
        return reward

    def is_done(self):
        return self.current == self.goal or self.time_step > 1000

class Agent:

    def __init__(self, action_space):
        self.action_space = action_space

    def act(self, observation):
        return self.action_space.sample()

def run_episode(env, agent):
    observation = env.current
    total_reward = 0
    done = False
    while not done:
        action = agent.act(observation)
        observation, reward, done = env.step(action)
        total_reward += reward
    return total_reward

def main():
    import numpy as np
    np.random.seed(42)
    env = Environment(start=0, goal=10, decay_rate=0.01)
    agent = Agent(action_space=np.random.RandomState(42))
    episode_reward = run_episode(env, agent)
    print(f'Episode reward: {episode_reward}')
if __name__ == '__main__':
    main()