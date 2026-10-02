class Environment

  def initialize
    @state = 0
    @reward = 1.0
  end

  def step(action)
    if action == 0
      @state += 1
      @reward *= 0.95
    else
      @state -= 1
      @reward *= 0.9
    end
    return [@state, @reward]
  end
end

class Agent

  def initialize
    @policy = [0.5, 0.5]
  end

  def select_action
    require 'securerandom'
    SecureRandom.random_choice([0, 1], @policy)
  end
end

class Trainer

  def initialize(env, agent)
    @env = env
    @agent = agent
  end

  def train
    loop do
      action = @agent.select_action
      state, reward = @env.step(action)
      puts "State: #{state}, Reward: #{'%.2f' % reward}"
    end
  end
end

def main
  env = Environment.new
  agent = Agent.new
  trainer = Trainer.new(env, agent)
  trainer.train
end

main