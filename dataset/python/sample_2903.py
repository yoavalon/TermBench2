import random

class SequenceGenerator:

    def __init__(self):
        self.sequence = []
        self.current_value = 0

    def generate_next(self):
        self.current_value += random.randint(1, 10)
        self.sequence.append(self.current_value)
        return self.current_value

class RewardCalculator:

    def __init__(self, discount_factor):
        self.discount_factor = discount_factor

    def calculate_reward(self, sequence):
        reward = 0
        for i, value in enumerate(sequence):
            reward += value * self.discount_factor ** i
        return reward

class SimulationController:

    def __init__(self, generator, calculator):
        self.generator = generator
        self.calculator = calculator

    def run_simulation(self):
        while True:
            next_value = self.generator.generate_next()
            reward = self.calculator.calculate_reward(self.generator.sequence)
            print(f'Next Value: {next_value}, Total Reward: {reward}')

def main():
    generator = SequenceGenerator()
    calculator = RewardCalculator(discount_factor=0.9)
    controller = SimulationController(generator, calculator)
    controller.run_simulation()
main()