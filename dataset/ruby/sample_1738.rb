require 'matrix'
require 'random'

class Environment
  def initialize
    @state = ['A', 'B', 'C'].sample
    @goal_state = 'C'
  end

  def step(action)
    if action == 'move'
      if @state == 'A'
        @state = 'B'
      elsif @state == 'B'
        @state = 'C'
      end
      return [@state, _reward]
    end
    return [@state, 0]
  end

  def _reward
    return 1 if @state == @goal_state else 0
  end
end

class Agent
  def initialize(env)
    @env = env
    @action = 'move'
  end

  def act
    state, reward = @env.step(@action)
    return [state, reward]
  end
end

class Controller
  def initialize(agent)
    @agent = agent
    @total_reward = 0
  end

  def run
    loop do
      state, reward = @agent.act
      @total_reward += reward
      if state == @agent.env.goal_state
        puts "Goal reached with total reward: #{@total_reward}"
      else
        puts "Current state: #{state}, Reward: #{reward}"
      end
    end
  end
end

def main
  env = Environment.new
  agent = Agent.new(env)
  controller = Controller.new(agent)
  controller.run
end

main