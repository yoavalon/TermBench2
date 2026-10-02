require 'matrix'

class SequenceGenerator
  def initialize(size)
    @size = size
    @sequence = Array.new(size) { rand }
  end

  def generate
    @sequence
  end
end

class RewardCalculator
  def initialize(discount_factor)
    @discount_factor = discount_factor
  end

  def calculate(sequence)
    reward = 0
    sequence.each_with_index do |value, t|
      reward += @discount_factor**t * value
    end
    reward
  end
end

class SequenceAnalyzer
  def initialize(reward_calculator)
    @reward_calculator = reward_calculator
  end

  def analyze(sequence)
    @reward_calculator.calculate(sequence)
  end
end

def main
  size = 10
  discount_factor = 0.9
  generator = SequenceGenerator.new(size)
  reward_calculator = RewardCalculator.new(discount_factor)
  analyzer = SequenceAnalyzer.new(reward_calculator)
  sequence = generator.generate
  reward = analyzer.analyze(sequence)
  puts "Sequence: #{sequence}"
  puts "Reward: #{reward}"
end

main