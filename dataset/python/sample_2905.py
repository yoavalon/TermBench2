class SequenceGenerator:

    def __init__(self, start, step):
        self.current = start
        self.step = step

    def next(self):
        value = self.current
        self.current += self.step
        return value

class RewardCalculator:

    def __init__(self, initial_reward, decay_rate):
        self.current_reward = initial_reward
        self.decay_rate = decay_rate

    def calculate(self):
        reward = self.current_reward
        self.current_reward *= self.decay_rate
        return reward

class Agent:

    def __init__(self, sequence, reward_calculator):
        self.sequence = sequence
        self.reward_calculator = reward_calculator
        self.total_reward = 0

    def step(self):
        action = self.sequence.next()
        reward = self.reward_calculator.calculate()
        self.total_reward += reward
        return (action, reward)

    def interact(self):
        while True:
            action, reward = self.step()
            print(f'Action: {action}, Reward: {reward}, Total Reward: {self.total_reward}')

def main():
    sequence = SequenceGenerator(0, 1)
    reward_calculator = RewardCalculator(1.0, 0.95)
    agent = Agent(sequence, reward_calculator)
    agent.interact()
main()