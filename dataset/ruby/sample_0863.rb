require 'securerandom'

class Environment
  def initialize
    @state = 0
    @goal = 5
  end

  def step(action)
    if action == 1
      @state += 1
    end
    if @state >= @goal
      reward = 1
      done = true
    else
      reward = -0.1
      done = false
    end
    [@state, reward, done]
  end
end

class Agent
  def initialize(epsilon, alpha, gamma)
    @epsilon = epsilon
    @alpha = alpha
    @gamma = gamma
    @q_table = {}
  end

  def select_action(state)
    if SecureRandom.random_number < @epsilon
      return [0, 1].sample
    else
      return @q_table.fetch(state, [0, 0]).max
    end
  end

  def update_q_table(state, action, reward, next_state, done)
    @q_table[state] ||= [0, 0]
    @q_table[next_state] ||= [0, 0]
    old_value = @q_table[state][action]
    next_max = @q_table[next_state].max
    new_value = old_value + @alpha * (reward + @gamma * next_max - old_value)
    @q_table[state][action] = new_value
  end
end

def main
  env = Environment.new
  agent = Agent.new(epsilon: 0.1, alpha: 0.5, gamma: 0.9)
  episodes = 1000
  episodes.times do |episode|
    state = 0
    done = false
    while !done
      action = agent.select_action(state)
      next_state, reward, done = env.step(action)
      agent.update_q_table(state, action, reward, next_state, done)
      state = next_state
    end
  end
end

main if __FILE__ == $0