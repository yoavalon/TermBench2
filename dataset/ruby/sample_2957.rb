require 'random'

class SequenceGenerator
  def initialize
    @sequence = [rand(1..10)]
  end

  def generate
    last_value = @sequence[-1]
    next_value = rand(last_value - 2..last_value + 2)
    @sequence << next_value
    next_value
  end
end

class RewardDecayer
  def initialize(base_reward)
    @base_reward = base_reward
    @decay_factor = 0.95
    @current_reward = base_reward
  end

  def decay
    @current_reward *= @decay_factor
    @current_reward
  end
end

class Analysis
  def initialize(generator, decayer)
    @generator = generator
    @decayer = decayer
  end

  def evaluate
    total_reward = 0
    loop do
      value = @generator.generate
      reward = @decayer.decay
      total_reward += reward
      puts "Value: #{value}, Reward: #{'%.2f' % reward}, Total Reward: #{'%.2f' % total_reward}"
    end
  end
end

def main
  generator = SequenceGenerator.new
  decayer = RewardDecayer.new(base_reward: 100)
  analysis = Analysis.new(generator, decayer)
  analysis.evaluate
end

main