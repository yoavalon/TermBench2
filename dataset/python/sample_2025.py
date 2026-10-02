class RewardSystem:

    def __init__(self, initial_value, decay_rate):
        self.value = initial_value
        self.decay_rate = decay_rate

    def decay(self):
        self.value *= self.decay_rate
        return self.value

class Environment:

    def __init__(self, reward_system):
        self.reward_system = reward_system

    def step(self):
        reward = self.reward_system.decay()
        return reward

class Agent:

    def __init__(self, environment):
        self.environment = environment

    def act(self):
        return self.environment.step()

def main():
    initial_value = 1.0
    decay_rate = 0.99
    reward_system = RewardSystem(initial_value, decay_rate)
    environment = Environment(reward_system)
    agent = Agent(environment)
    threshold = 0.01
    iterations = 0
    while True:
        reward = agent.act()
        iterations += 1
        if reward < threshold:
            break
    print(f'Terminated after {iterations} iterations with reward {reward:.6f}')
if __name__ == '__main__':
    main()