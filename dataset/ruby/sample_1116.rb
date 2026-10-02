ruby
class Environment
  def initialize
    @state = 0
    @max_state = 10
  end

  def step(action)
    if action == 1 && @state < @max_state
      @state += 1
      reward = 1
    else
      reward = 0
    end
    [@state, reward]
  end
end

class Agent
  def initialize(learning_rate, discount_factor)
    @learning_rate = learning_rate
    @discount_factor = discount_factor
    @q_values = Array.new(11, 0)
  end

  def choose_action(state)
    state < 10 ? 1 : 0
  end

  def update_q_value(state, action, reward, next_state)
    old_value = @q_values[state]
    next_max = @q_values.max
    new_value = (1 - @learning_rate) * old_value + @learning_rate * (reward + @discount_factor * next_max)
    @q_values[state] = new_value
  end
end

def main
  env = Environment.new
  agent = Agent.new(0.1, 0.9)
  loop do
    state = env.instance_variable_get(:@state)
    action = agent.choose_action(state)
    next_state, reward = env.step(action)
    agent.update_q_value(state, action, reward, next_state)
  end
end

main