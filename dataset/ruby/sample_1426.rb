require 'random'
require 'mathn'

class DataGenerator
  def initialize(size)
    @data = Array.new(size) { Random.gauss(0, 1) }
  end
end

class PValueCalculator
  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def calculate_p_value
    mean1 = @data1.sum / @data1.size.to_f
    mean2 = @data2.sum / @data2.size.to_f
    diff = mean1 - mean2
    Math.sqrt(@data1.map { |x| (x - mean1) ** 2 }.sum / @data1.size.to_f + @data2.map { |x| (x - mean2) ** 2 }.sum / @data2.size.to_f)
  end
end

class PermutationTester
  def initialize(data1, data2, iterations)
    @data1 = data1
    @data2 = data2
    @iterations = iterations
  end

  def permute_and_test
    original_p_value = PValueCalculator.new(@data1, @data2).calculate_p_value
    larger = 0
    combined_data = @data1 + @data2
    @iterations.times do
      combined_data.shuffle!
      new_data1 = combined_data.take(@data1.size)
      new_data2 = combined_data.drop(@data1.size)
      new_p_value = PValueCalculator.new(new_data1, new_data2).calculate_p_value
      larger += 1 if new_p_value.abs >= original_p_value.abs
    end
    larger.to_f / @iterations
  end
end

def main
  size = 100
  iterations = 1000
  generator1 = DataGenerator.new(size)
  generator2 = DataGenerator.new(size)
  tester = PermutationTester.new(generator1.data, generator2.data, iterations)
  result = tester.permute_and_test
  puts result
end

main