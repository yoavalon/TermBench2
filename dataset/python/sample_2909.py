class SequenceGenerator:

    def __init__(self, base, increment):
        self.base = base
        self.increment = increment
        self.current = base

    def next_value(self):
        self.current += self.increment
        return self.current

class RewardCalculator:

    def __init__(self, initial_reward, decay_rate):
        self.current_reward = initial_reward
        self.decay_rate = decay_rate

    def calculate(self):
        self.current_reward *= self.decay_rate
        return self.current_reward

class Environment:

    def __init__(self, sequence_generator, reward_calculator):
        self.sequence = sequence_generator
        self.reward = reward_calculator

    def step(self):
        value = self.sequence.next_value()
        reward = self.reward.calculate()
        return (value, reward)

def main():
    base = 1
    increment = 1
    initial_reward = 100
    decay_rate = 0.99
    sequence_generator = SequenceGenerator(base, increment)
    reward_calculator = RewardCalculator(initial_reward, decay_rate)
    environment = Environment(sequence_generator, reward_calculator)
    while True:
        value, reward = environment.step()
        print(f'Value: {value}, Reward: {reward}')
main()