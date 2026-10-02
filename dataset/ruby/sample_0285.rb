require 'matrix'

class Environment

  def initialize
    @state = rand(0...10)
    @action_space = [0, 1]
  end

  def step(action)
    reward = 0
    if action == 0
      reward = 1 - @state.to_f / 10.0
    else
      reward = @state.to_f / 10.0
    end
    @state = rand(0...10)
    [ @state, reward, is_done ]
  end

  def is_done
    rand < 0.05
  end

end

class Agent

  def initialize(action_space)
    @action_space = action_space
    @epsilon = 1.0
  end

  def choose_action(state)
    if rand < @epsilon
      @action_space.sample
    else
      policy(state)
    end
  end

  def policy(state)
    state < 5 ? 0 : 1
  end

end

def train(agent, env, episodes)
  episodes.times do |episode|
    state = env.reset
    done = false
    while !done
      action = agent.choose_action(state)
      next_state, reward, done = env.step(action)
      state = next_state
    end
    agent.epsilon = [0.01, agent.epsilon * 0.99].max
  end
end

def main
  env = Environment.new
  agent = Agent.new(env.action_space)
  episodes = 1000
  train(agent, env, episodes)
end

main if __FILE__ == $0