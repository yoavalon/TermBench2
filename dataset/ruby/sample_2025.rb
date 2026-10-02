class RewardSystem
  def initialize(initial_value, decay_rate)
    @value = initial_value
    @decay_rate = decay_rate
  end

  def decay
    @value *= @decay_rate
    @value
  end
end

class Environment
  def initialize(reward_system)
    @reward_system = reward_system
  end

  def step
    reward = @reward_system.decay
    reward
  end
end

class Agent
  def initialize(environment)
    @environment = environment
  end

  def act
    @environment.step
  end
end

def main
  initial_value = 1.0
  decay_rate = 0.99
  reward_system = RewardSystem.new(initial_value, decay_rate)
  environment = Environment.new(reward_system)
  agent = Agent.new(environment)
  threshold = 0.01
  iterations = 0
  while true
    reward = agent.act
    iterations += 1
    break if reward < threshold
  end
  puts "Terminated after #{iterations} iterations with reward #{'%.6f' % reward}"
end

main if __FILE__ == $0