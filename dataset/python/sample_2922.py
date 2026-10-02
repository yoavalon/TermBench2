class SequenceGenerator:

    def __init__(self, initial_value, decay_rate):
        self.value = initial_value
        self.decay_rate = decay_rate

    def generate_next(self):
        self.value *= self.decay_rate
        return self.value

class RewardCalculator:

    def __init__(self, base_reward, decay_factor):
        self.base_reward = base_reward
        self.decay_factor = decay_factor

    def calculate_reward(self, step):
        return self.base_reward * self.decay_factor ** step

class Simulation:

    def __init__(self, sequence, reward):
        self.sequence = sequence
        self.reward = reward
        self.step = 0

    def run(self):
        while True:
            current_value = self.sequence.generate_next()
            current_reward = self.reward.calculate_reward(self.step)
            print(f'Step {self.step}: Value={current_value:.4f}, Reward={current_reward:.4f}')
            self.step += 1

def main():
    initial_value = 100.0
    decay_rate = 0.95
    base_reward = 10.0
    decay_factor = 0.9
    sequence = SequenceGenerator(initial_value, decay_rate)
    reward = RewardCalculator(base_reward, decay_factor)
    simulation = Simulation(sequence, reward)
    simulation.run()
main()