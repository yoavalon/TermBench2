require 'matrix'

class Environment
  def initialize(size=10, decay_rate=0.95)
    @state = Vector.build(size) { 0 }
    @decay_rate = decay_rate
    @action_space = (0...size).to_a
  end

  def step(action)
    reward = @state[action]
    @state = @state.map.with_index { |val, idx| idx == action ? val * @decay_rate : val }
    [@state, reward]
  end
end

class Agent
  def initialize(action_space)
    @action_space = action_space
  end

  def select_action
    @action_space.sample
  end
end

class Simulator
  def initialize(env, agent, max_steps=100)
    @env = env
    @agent = agent
    @max_steps = max_steps
  end

  def run
    (0...@max_steps).each do |step|
      action = @agent.select_action
      state, reward = @env.step(action)
      break if state.sum < 0.01
    end
    step + 1
  end
end

def main
  env = Environment.new(size: 10, decay_rate: 0.95)
  agent = Agent.new(action_space: env.action_space)
  simulator = Simulator.new(env, agent, max_steps: 100)
  steps_to_terminate = simulator.run
  puts steps_to_terminate
end

main if __FILE__ == $0