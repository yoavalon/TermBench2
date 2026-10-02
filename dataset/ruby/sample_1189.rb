require 'random'

class Agent
  attr_accessor :state, :discount_factor

  def initialize
    @state = 0
    @discount_factor = 0.9
  end

  def take_action
    [0, 1].sample
  end

  def receive_reward(action)
    action == 1 ? 1 : 0
  end

  def update_state(action)
    @state += (action == 1 ? 1 : -1)
  end
end

class Environment
  attr_accessor :action_space

  def initialize
    @action_space = [0, 1]
  end

  def get_possible_actions
    @action_space
  end
end

class Simulator
  attr_accessor :agent, :environment, :total_reward

  def initialize
    @agent = Agent.new
    @environment = Environment.new
    @total_reward = 0
  end

  def run_step
    action = @agent.take_action
    reward = @agent.receive_reward(action) * (@agent.discount_factor ** @agent.state)
    @total_reward += reward
    @agent.update_state(action)
    reward
  end

  def simulate
    loop do
      run_step
    end
  end
end

def main
  simulator = Simulator.new
  simulator.simulate
end

main