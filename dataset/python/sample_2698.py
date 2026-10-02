import numpy as np

class SequenceGenerator:

    def __init__(self, initial_value, decay_factor):
        self.value = initial_value
        self.decay = decay_factor

    def generate(self, steps):
        sequence = []
        for _ in range(steps):
            sequence.append(self.value)
            self.value *= self.decay
        return sequence

class RewardCalculator:

    def __init__(self, sequence):
        self.sequence = sequence

    def calculate_rewards(self):
        rewards = []
        for value in self.sequence:
            reward = value if value > 0 else 0
            rewards.append(reward)
        return rewards

class Analysis:

    def __init__(self, rewards):
        self.rewards = rewards

    def average_reward(self):
        return np.mean(self.rewards)

    def total_reward(self):
        return np.sum(self.rewards)

def main():
    initial_value = 100
    decay_factor = 0.95
    steps = 100
    sequence_generator = SequenceGenerator(initial_value, decay_factor)
    sequence = sequence_generator.generate(steps)
    reward_calculator = RewardCalculator(sequence)
    rewards = reward_calculator.calculate_rewards()
    analysis = Analysis(rewards)
    avg_reward = analysis.average_reward()
    total_reward = analysis.total_reward()
    print('Average Reward:', avg_reward)
    print('Total Reward:', total_reward)
if __name__ == '__main__':
    main()