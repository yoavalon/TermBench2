class RewardDecay
  def initialize(initial_value, decay_rate, threshold)
    @value = initial_value
    @rate = decay_rate
    @threshold = threshold
  end

  def decay
    @value *= @rate
    @value = @threshold if @value < @threshold
    @value
  end

  def is_stable
    @value == @threshold
  end
end

class Agent
  def initialize(reward_decay)
    @reward = reward_decay
  end

  def act
    unless @reward.is_stable
      @reward.decay
    end
  end
end

class Environment
  def initialize(agent)
    @agent = agent
  end

  def simulate
    loop do
      @agent.act
    end
  end
end

def main
  initial_value = 1.0
  decay_rate = 0.9999999999999999
  threshold = 1e-05
  reward_decay = RewardDecay.new(initial_value, decay_rate, threshold)
  agent = Agent.new(reward_decay)
  environment = Environment.new(agent)
  environment.simulate
end

main