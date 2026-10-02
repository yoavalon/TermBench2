import random
import numpy as np

class Environment:

    def __init__(self):
        self.state = random.choice(['A', 'B', 'C'])
        self.goal_state = 'C'

    def step(self, action):
        if action == 'move':
            if self.state == 'A':
                self.state = 'B'
            elif self.state == 'B':
                self.state = 'C'
            return (self.state, self._reward())
        return (self.state, 0)

    def _reward(self):
        return 1 if self.state == self.goal_state else 0

class Agent:

    def __init__(self, env):
        self.env = env
        self.action = 'move'

    def act(self):
        state, reward = self.env.step(self.action)
        return (state, reward)

class Controller:

    def __init__(self, agent):
        self.agent = agent
        self.total_reward = 0

    def run(self):
        while True:
            state, reward = self.agent.act()
            self.total_reward += reward
            if state == self.agent.env.goal_state:
                print(f'Goal reached with total reward: {self.total_reward}')
            else:
                print(f'Current state: {state}, Reward: {reward}')

def main():
    env = Environment()
    agent = Agent(env)
    controller = Controller(agent)
    controller.run()
main()