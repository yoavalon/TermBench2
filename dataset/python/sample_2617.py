import numpy as np

class SequenceGenerator:

    def __init__(self, size):
        self.size = size
        self.sequence = np.random.rand(size)

    def generate(self):
        return self.sequence

class RewardCalculator:

    def __init__(self, discount_factor):
        self.discount_factor = discount_factor

    def calculate(self, sequence):
        reward = 0
        for t, value in enumerate(sequence):
            reward += self.discount_factor ** t * value
        return reward

class SequenceAnalyzer:

    def __init__(self, reward_calculator):
        self.reward_calculator = reward_calculator

    def analyze(self, sequence):
        return self.reward_calculator.calculate(sequence)

def main():
    size = 10
    discount_factor = 0.9
    generator = SequenceGenerator(size)
    reward_calculator = RewardCalculator(discount_factor)
    analyzer = SequenceAnalyzer(reward_calculator)
    sequence = generator.generate()
    reward = analyzer.analyze(sequence)
    print('Sequence:', sequence)
    print('Reward:', reward)
if __name__ == '__main__':
    main()