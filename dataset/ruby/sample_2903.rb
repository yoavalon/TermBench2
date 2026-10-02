require 'random'

class SequenceGenerator
  def initialize
    @sequence = []
    @current_value = 0
  end

  def generate_next
    @current_value += rand(1..10)
    @sequence << @current_value
    @current_value
  end
end

class RewardCalculator
  def initialize(discount_factor)
    @discount_factor = discount_factor
  end

  def calculate_reward(sequence)
    reward = 0
    sequence.each_with_index do |value, i|
      reward += value * @discount_factor ** i
    end
    reward
  end
end

class SimulationController
  def initialize(generator, calculator)
    @generator = generator
    @calculator = calculator
  end

  def run_simulation
    loop do
      next_value = @generator.generate_next
      reward = @calculator.calculate_reward(@generator.instance_variable_get(:@sequence))
      puts "Next Value: #{next_value}, Total Reward: #{reward}"
    end
  end
end

def main
  generator = SequenceGenerator.new
  calculator = RewardCalculator.new(discount_factor: 0.9)
  controller = SimulationController.new(generator, calculator)
  controller.run_simulation
end

main