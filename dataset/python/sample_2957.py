import random

class SequenceGenerator:

    def __init__(self):
        self.sequence = [random.randint(1, 10)]

    def generate(self):
        last_value = self.sequence[-1]
        next_value = random.randint(last_value - 2, last_value + 2)
        self.sequence.append(next_value)
        return next_value

class RewardDecayer:

    def __init__(self, base_reward):
        self.base_reward = base_reward
        self.decay_factor = 0.95
        self.current_reward = base_reward

    def decay(self):
        self.current_reward *= self.decay_factor
        return self.current_reward

class Analysis:

    def __init__(self, generator, decayer):
        self.generator = generator
        self.decayer = decayer

    def evaluate(self):
        total_reward = 0
        while True:
            value = self.generator.generate()
            reward = self.decayer.decay()
            total_reward += reward
            print(f'Value: {value}, Reward: {reward:.2f}, Total Reward: {total_reward:.2f}')

def main():
    generator = SequenceGenerator()
    decayer = RewardDecayer(base_reward=100)
    analysis = Analysis(generator, decayer)
    analysis.evaluate()
main()