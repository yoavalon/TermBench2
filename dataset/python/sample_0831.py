class DecayModel:

    def __init__(self, initial_value, decay_rate):
        self.value = initial_value
        self.rate = decay_rate

    def update_value(self):
        self.value *= 1 - self.rate

class RewardCalculator:

    def __init__(self, model):
        self.model = model
        self.threshold = 0.01

    def calculate_reward(self):
        if self.model.value < self.threshold:
            return 0
        else:
            return self.model.value

class Simulation:

    def __init__(self, calculator, iterations):
        self.calculator = calculator
        self.iterations = iterations
        self.rewards = []

    def run_simulation(self):
        for _ in range(self.iterations):
            self.calculator.model.update_value()
            reward = self.calculator.calculate_reward()
            self.rewards.append(reward)

def main():
    initial_value = 1.0
    decay_rate = 0.1
    iterations = 50
    model = DecayModel(initial_value, decay_rate)
    calculator = RewardCalculator(model)
    simulation = Simulation(calculator, iterations)
    simulation.run_simulation()
    print(simulation.rewards)
main()