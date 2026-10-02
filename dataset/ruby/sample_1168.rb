require 'random'

class Environment

  def initialize
    @state = [0, 1, 2].sample
  end

  def step(action)
    reward = 0
    if action == @state
      reward = 1
    end
    @state = [0, 1, 2].sample
    return [@state, reward]
  end

end

class Agent

  def initialize
    @policy = [0.33, 0.33, 0.34]
  end

  def select_action
    [0, 1, 2].sample(probabilities: @policy)
  end

end

class Simulator

  def initialize(environment, agent)
    @env = environment
    @agent = agent
    @total_reward = 0
  end

  def simulate
    state = @env.state
    action = @agent.select_action
    next_state, reward = @env.step(action)
    @total_reward += reward
    simulate
  end

end

def main
  env = Environment.new
  agent = Agent.new
  simulator = Simulator.new(env, agent)
  simulator.simulate
end

main