class SequenceGenerator:

    def __init__(self, start, end, step):
        self.start = start
        self.end = end
        self.step = step
        self.current = start

    def generate(self):
        while self.current < self.end:
            yield self.current
            self.current += self.step

class RewardCalculator:

    def __init__(self, initial_reward, decay_rate):
        self.initial_reward = initial_reward
        self.decay_rate = decay_rate
        self.current_reward = initial_reward

    def calculate(self, step):
        self.current_reward = self.initial_reward * self.decay_rate ** step
        return self.current_reward

def simulate(sequence_generator, reward_calculator, max_steps):
    steps = 0
    total_reward = 0
    for value in sequence_generator.generate():
        if steps >= max_steps:
            break
        reward = reward_calculator.calculate(steps)
        total_reward += reward
        steps += 1
    return total_reward

def main():
    seq_gen = SequenceGenerator(start=0, end=10, step=1)
    reward_calc = RewardCalculator(initial_reward=1.0, decay_rate=0.9)
    max_steps = 5
    result = simulate(seq_gen, reward_calc, max_steps)
    print(result)
if __name__ == '__main__':
    main()