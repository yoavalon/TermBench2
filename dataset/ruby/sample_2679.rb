class SequenceGenerator
  def initialize(start, end, step)
    @start = start
    @end = end
    @step = step
    @current = start
  end

  def generate
    if @current < @end
      value = @current
      @current += @step
      value
    else
      nil
    end
  end
end

class RewardCalculator
  def initialize(decay_rate)
    @decay_rate = decay_rate
    @current_reward = 1.0
  end

  def calculate
    @current_reward *= @decay_rate
    @current_reward
  end
end

def process_sequence
  seq_gen = SequenceGenerator.new(1, 10, 1)
  reward_calc = RewardCalculator.new(0.95)
  total_reward = 0.0
  while true
    value = seq_gen.generate
    break if value.nil?
    reward = reward_calc.calculate
    total_reward += reward
  end
  total_reward
end

def main
  result = process_sequence
  puts result
end

main