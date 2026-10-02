import random

class Environment:

    def __init__(self):
        self.state = 0
        self.goal = 5

    def step(self, action):
        if action == 1:
            self.state += 1
        if self.state >= self.goal:
            reward = 1
            done = True
        else:
            reward = -0.1
            done = False
        return (self.state, reward, done)

class Agent:

    def __init__(self, epsilon, alpha, gamma):
        self.epsilon = epsilon
        self.alpha = alpha
        self.gamma = gamma
        self.q_table = {}

    def select_action(self, state):
        if random.random() < self.epsilon:
            return random.choice([0, 1])
        else:
            return max(self.q_table.get(state, [0, 0]))

    def update_q_table(self, state, action, reward, next_state, done):
        if state not in self.q_table:
            self.q_table[state] = [0, 0]
        if next_state not in self.q_table:
            self.q_table[next_state] = [0, 0]
        old_value = self.q_table[state][action]
        next_max = max(self.q_table[next_state])
        new_value = old_value + self.alpha * (reward + self.gamma * next_max - old_value)
        self.q_table[state][action] = new_value

def main():
    env = Environment()
    agent = Agent(epsilon=0.1, alpha=0.5, gamma=0.9)
    episodes = 1000
    for episode in range(episodes):
        state = env.reset()
        done = False
        while not done:
            action = agent.select_action(state)
            next_state, reward, done = env.step(action)
            agent.update_q_table(state, action, reward, next_state, done)
            state = next_state
if __name__ == '__main__':
    main()