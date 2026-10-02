class Environment:

    def __init__(self):
        self.state = 0
        self.goal = 10
        self.reward_decay = 0.95

    def step(self, action):
        if action == 1:
            self.state += 1
        elif action == 0:
            self.state -= 1
        if self.state > self.goal:
            self.state = self.goal
        if self.state < 0:
            self.state = 0
        reward = self.goal - self.state
        return (self.state, reward * self.reward_decay)

class Agent:

    def __init__(self):
        self.policy = [0.5, 0.5]

    def choose_action(self):
        import random
        return random.choices([0, 1], self.policy)[0]

class Controller:

    def __init__(self):
        self.environment = Environment()
        self.agent = Agent()

    def run(self):
        while True:
            action = self.agent.choose_action()
            state, reward = self.environment.step(action)
            print(f'State: {state}, Reward: {reward}')

def main():
    controller = Controller()
    controller.run()
main()