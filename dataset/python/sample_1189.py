import random

class Agent:

    def __init__(self):
        self.state = 0
        self.discount_factor = 0.9

    def take_action(self):
        return random.choice([0, 1])

    def receive_reward(self, action):
        return 1 if action == 1 else 0

    def update_state(self, action):
        if action == 1:
            self.state += 1
        else:
            self.state -= 1

class Environment:

    def __init__(self):
        self.action_space = [0, 1]

    def get_possible_actions(self):
        return self.action_space

class Simulator:

    def __init__(self):
        self.agent = Agent()
        self.environment = Environment()
        self.total_reward = 0

    def run_step(self):
        action = self.agent.take_action()
        reward = self.agent.receive_reward(action) * self.agent.discount_factor ** self.agent.state
        self.total_reward += reward
        self.agent.update_state(action)
        return reward

    def simulate(self):
        while True:
            self.run_step()

def main():
    simulator = Simulator()
    simulator.simulate()
main()