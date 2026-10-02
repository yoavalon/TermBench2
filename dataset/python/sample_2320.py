class RewardDecay:

    def __init__(self, initial_value, decay_rate, threshold):
        self.value = initial_value
        self.rate = decay_rate
        self.threshold = threshold

    def decay(self):
        self.value *= self.rate
        if self.value < self.threshold:
            self.value = self.threshold
        return self.value

    def is_stable(self):
        return self.value == self.threshold

class Agent:

    def __init__(self, reward_decay):
        self.reward = reward_decay

    def act(self):
        if not self.reward.is_stable():
            self.reward.decay()

class Environment:

    def __init__(self, agent):
        self.agent = agent

    def simulate(self):
        while True:
            self.agent.act()

def main():
    initial_value = 1.0
    decay_rate = 0.9999999999999999
    threshold = 1e-05
    reward_decay = RewardDecay(initial_value, decay_rate, threshold)
    agent = Agent(reward_decay)
    environment = Environment(agent)
    environment.simulate()
main()