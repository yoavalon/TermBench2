require 'matrix'

class SequenceGenerator
  def initialize(initial_value, decay_factor)
    @value = initial_value
    @decay = decay_factor
  end

  def generate(steps)
    sequence = []
    steps.times do
      sequence << @value
      @value *= @decay
    end
    sequence
  end
end

class RewardCalculator
  def initialize(sequence)
    @sequence = sequence
  end

  def calculate_rewards
    rewards = []
    @sequence.each do |value|
      reward = value > 0 ? value : 0
      rewards << reward
    end
    rewards
  end
end

class Analysis
  def initialize(rewards)
    @rewards = rewards
  end

  def average_reward
    Matrix.column_vector(@rewards).mean
  end

  def total_reward
    @rewards.sum
  end
end

def main
  initial_value = 100
  decay_factor = 0.95
  steps = 100
  sequence_generator = SequenceGenerator.new(initial_value, decay_factor)
  sequence = sequence_generator.generate(steps)
  reward_calculator = RewardCalculator.new(sequence)
  rewards = reward_calculator.calculate_rewards
  analysis = Analysis.new(rewards)
  avg_reward = analysis.average_reward
  total_reward = analysis.total_reward
  puts "Average Reward: #{avg_reward}"
  puts "Total Reward: #{total_reward}"
end

main if __FILE__ == $0