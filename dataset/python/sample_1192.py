class Agent:

    def __init__(self, state, action):
        self.state = state
        self.action = action

    def update_state(self, new_state):
        self.state = new_state

    def choose_action(self):
        return self.action

class Environment:

    def __init__(self, initial_state, reward_function):
        self.state = initial_state
        self.reward_function = reward_function

    def step(self, action):
        new_state = self.state + 1
        reward = self.reward_function(new_state)
        self.state = new_state
        return (new_state, reward)

class Controller:

    def __init__(self, agent, environment):
        self.agent = agent
        self.environment = environment

    def execute(self):
        while True:
            action = self.agent.choose_action()
            new_state, reward = self.environment.step(action)
            self.agent.update_state(new_state)

def reward_decay(state):
    return 1 / (state + 1)

def main():
    initial_state = 0
    action = 0
    agent = Agent(initial_state, action)
    environment = Environment(initial_state, reward_decay)
    controller = Controller(agent, environment)
    controller.execute()
main()