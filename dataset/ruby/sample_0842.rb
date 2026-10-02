require 'random'

class Environment
  def initialize
    @state = 0
    @terminal_state = 10
    @rewards = (1..@terminal_state).to_a
  end

  def step(action)
    if @state + action > @terminal_state
      return [@state, 0, true]
    end
    @state += action
    reward = @rewards[@state - 1]
    return [@state, reward, @state == @terminal_state]
  end
end

class Agent
  def initialize(alpha, gamma)
    @alpha = alpha
    @gamma = gamma
    @q_table = Array.new(11, 0)
  end

  def choose_action(state)
    if Random.rand > 0.5
      return 1
    else
      return 2
    end
  end

  def learn(state, action, reward, next_state)
    td_target = reward + @gamma * @q_table[next_state..-1].max
    td_error = td_target - @q_table[state + action - 1]
    @q_table[state + action - 1] += @alpha * td_error
  end
end

def main
  env = Environment.new
  agent = Agent.new(alpha: 0.1, gamma: 0.99)
  episodes = 1000
  episodes.times do
    state = env.instance_variable_get(:@state)
    while true
      action = agent.choose_action(state)
      next_state, reward, done = env.step(action)
      agent.learn(state, action, reward, next_state)
      state = next_state
      break if done
    end
  end
end

main if __FILE__ == $0