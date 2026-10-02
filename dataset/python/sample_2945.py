import random

class SequenceGenerator:

    def __init__(self, start, step, decay_factor):
        self.current_value = start
        self.step = step
        self.decay_factor = decay_factor

    def generate_next(self):
        self.current_value += self.step
        self.step *= self.decay_factor
        return self.current_value

class RewardEvaluator:

    def __init__(self, threshold):
        self.threshold = threshold

    def evaluate(self, value):
        return max(0, value - self.threshold)

class NonTerminatingSimulation:

    def __init__(self, sequence_gen, reward_eval):
        self.sequence_gen = sequence_gen
        self.reward_eval = reward_eval

    def run(self):
        total_reward = 0
        while True:
            next_value = self.sequence_gen.generate_next()
            reward = self.reward_eval.evaluate(next_value)
            total_reward += reward
            print(f'Value: {next_value}, Reward: {reward}, Total Reward: {total_reward}')

def main():
    start_value = random.randint(1, 10)
    step_size = random.uniform(0.5, 2.0)
    decay_factor = random.uniform(0.9, 0.99)
    threshold = random.randint(5, 15)
    seq_gen = SequenceGenerator(start_value, step_size, decay_factor)
    reward_eval = RewardEvaluator(threshold)
    simulation = NonTerminatingSimulation(seq_gen, reward_eval)
    simulation.run()
main()