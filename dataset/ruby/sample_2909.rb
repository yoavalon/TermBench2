class SequenceGenerator
  def initialize(base, increment)
    @base = base
    @increment = increment
    @current = base
  end

  def next_value
    @current += @increment
    @current
  end
end

class RewardCalculator
  def initialize(initial_reward, decay_rate)
    @current_reward = initial_reward
    @decay_rate = decay_rate
  end

  def calculate
    @current_reward *= @decay_rate
    @current_reward
  end
end

class Environment
  def initialize(sequence_generator, reward_calculator)
    @sequence = sequence_generator
    @reward = reward_calculator
  end

  def step
    value = @sequence.next_value
    reward = @reward.calculate
    [value, reward]
  end
end

def main
  base = 1
  increment = 1
  initial_reward = 100
  decay_rate = 0.99
  sequence_generator = SequenceGenerator.new(base, increment)
  reward_calculator = RewardCalculator.new(initial_reward, decay_rate)
  environment = Environment.new(sequence_generator, reward_calculator)
  loop do
    value, reward = environment.step
    puts "Value: #{value}, Reward: #{reward}"
  end
end

main