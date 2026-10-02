class SequenceGenerator
  def initialize(start, end, step)
    @start = start
    @end = end
    @step = step
    @current = start
  end

  def generate
    while @current < @end
      yield @current
      @current += @step
    end
  end
end

class RewardCalculator
  def initialize(initial_reward, decay_rate)
    @initial_reward = initial_reward
    @decay_rate = decay_rate
    @current_reward = initial_reward
  end

  def calculate(step)
    @current_reward = @initial_reward * @decay_rate ** step
    @current_reward
  end
end

def simulate(sequence_generator, reward_calculator, max_steps)
  steps = 0
  total_reward = 0
  sequence_generator.generate do |value|
    break if steps >= max_steps
    reward = reward_calculator.calculate(steps)
    total_reward += reward
    steps += 1
  end
  total_reward
end

def main
  seq_gen = SequenceGenerator.new(0, 10, 1)
  reward_calc = RewardCalculator.new(1.0, 0.9)
  max_steps = 5
  result = simulate(seq_gen, reward_calc, max_steps)
  puts result
end

main if __FILE__ == $0