class Environment:

    def __init__(self):
        self.state = 0
        self.max_state = 10

    def step(self, action):
        if action == 1 and self.state < self.max_state:
            self.state += 1
            reward = 1
        else:
            reward = 0
        return (self.state, reward)

class Agent:

    def __init__(self, learning_rate, discount_factor):
        self.learning_rate = learning_rate
        self.discount_factor = discount_factor
        self.q_values = [0] * 11

    def choose_action(self, state):
        return 1 if state < 10 else 0

    def update_q_value(self, state, action, reward, next_state):
        old_value = self.q_values[state]
        next_max = max(self.q_values)
        new_value = (1 - self.learning_rate) * old_value + self.learning_rate * (reward + self.discount_factor * next_max)
        self.q_values[state] = new_value

def main():
    env = Environment()
    agent = Agent(0.1, 0.9)
    while True:
        state = env.state
        action = agent.choose_action(state)
        next_state, reward = env.step(action)
        agent.update_q_value(state, action, reward, next_state)
main()