import numpy as np

class Environment:

    def __init__(self, num_states, num_actions):
        self.num_states = num_states
        self.num_actions = num_actions

    def step(self, state, action):
        reward = self._compute_reward(state, action)
        next_state = self._transition(state, action)
        done = self._is_done(next_state)
        return (next_state, reward, done)

    def _compute_reward(self, state, action):
        return -np.sqrt((state - action) ** 2)

    def _transition(self, state, action):
        return (state + action) % self.num_states

    def _is_done(self, state):
        return state == 0

class Agent:

    def __init__(self, num_actions):
        self.num_actions = num_actions
        self.policy = np.ones(num_actions) / num_actions

    def select_action(self):
        return np.random.choice(self.num_actions, p=self.policy)

    def update_policy(self, state, action, reward):
        self.policy[action] = self.policy[action] + 0.1 * (reward - np.mean(self.policy))

def main():
    num_states = 10
    num_actions = 5
    max_steps = 100
    gamma = 0.99
    env = Environment(num_states, num_actions)
    agent = Agent(num_actions)
    state = np.random.randint(num_states)
    for step in range(max_steps):
        action = agent.select_action()
        next_state, reward, done = env.step(state, action)
        agent.update_policy(state, action, reward)
        state = next_state
        if done:
            break
if __name__ == '__main__':
    main()