require 'random'

class SequenceGenerator

  def initialize(start, step, decay_factor)
    @current_value = start
    @step = step
    @decay_factor = decay_factor
  end

  def generate_next
    @current_value += @step
    @step *= @decay_factor
    @current_value
  end
end

class RewardEvaluator

  def initialize(threshold)
    @threshold = threshold
  end

  def evaluate(value)
    [0, value - @threshold].max
  end
end

class NonTerminatingSimulation

  def initialize(sequence_gen, reward_eval)
    @sequence_gen = sequence_gen
    @reward_eval = reward_eval
  end

  def run
    total_reward = 0
    loop do
      next_value = @sequence_gen.generate_next
      reward = @reward_eval.evaluate(next_value)
      total_reward += reward
      puts "Value: #{next_value}, Reward: #{reward}, Total Reward: #{total_reward}"
    end
  end
end

def main
  start_value = rand(1..10)
  step_size = rand(0.5..2.0)
  decay_factor = rand(0.9..0.99)
  threshold = rand(5..15)
  seq_gen = SequenceGenerator.new(start_value, step_size, decay_factor)
  reward_eval = RewardEvaluator.new(threshold)
  simulation = NonTerminatingSimulation.new(seq_gen, reward_eval)
  simulation.run
end

main