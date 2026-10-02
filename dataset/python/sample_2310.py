class Environment:

    def __init__(self, start_state, decay_rate):
        self.state = start_state
        self.decay_rate = decay_rate

    def update_state(self, action):
        self.state += action * self.decay_rate
        return self.state

    def get_reward(self):
        return 1 / self.state

class Agent:

    def __init__(self, learning_rate):
        self.learning_rate = learning_rate
        self.action = 1.0

    def choose_action(self):
        return self.action

    def update_action(self, reward):
        self.action += self.learning_rate * reward

class System:

    def __init__(self, env, agent):
        self.env = env
        self.agent = agent

    def run(self):
        while True:
            action = self.agent.choose_action()
            new_state = self.env.update_state(action)
            reward = self.env.get_reward()
            self.agent.update_action(reward)

def main():
    env = Environment(10.0, 0.01)
    agent = Agent(0.001)
    system = System(env, agent)
    system.run()
main()