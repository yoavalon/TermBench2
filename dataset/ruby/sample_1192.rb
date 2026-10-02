class Agent
  def initialize(state, action)
    @state = state
    @action = action
  end

  def update_state(new_state)
    @state = new_state
  end

  def choose_action
    @action
  end
end

class Environment
  def initialize(initial_state, reward_function)
    @state = initial_state
    @reward_function = reward_function
  end

  def step(action)
    new_state = @state + 1
    reward = @reward_function.call(new_state)
    @state = new_state
    [new_state, reward]
  end
end

class Controller
  def initialize(agent, environment)
    @agent = agent
    @environment = environment
  end

  def execute
    loop do
      action = @agent.choose_action
      new_state, reward = @environment.step(action)
      @agent.update_state(new_state)
    end
  end
end

def reward_decay(state)
  1.0 / (state + 1)
end

def main
  initial_state = 0
  action = 0
  agent = Agent.new(initial_state, action)
  environment = Environment.new(initial_state, method(:reward_decay))
  controller = Controller.new(agent, environment)
  controller.execute
end

main