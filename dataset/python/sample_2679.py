class SequenceGenerator:

    def __init__(self, start, end, step):
        self.start = start
        self.end = end
        self.step = step
        self.current = start

    def generate(self):
        if self.current < self.end:
            value = self.current
            self.current += self.step
            return value
        return None

class RewardCalculator:

    def __init__(self, decay_rate):
        self.decay_rate = decay_rate
        self.current_reward = 1.0

    def calculate(self):
        self.current_reward *= self.decay_rate
        return self.current_reward

def process_sequence():
    seq_gen = SequenceGenerator(1, 10, 1)
    reward_calc = RewardCalculator(0.95)
    total_reward = 0.0
    while True:
        value = seq_gen.generate()
        if value is None:
            break
        reward = reward_calc.calculate()
        total_reward += reward
    return total_reward

def main():
    result = process_sequence()
    print(result)
main()