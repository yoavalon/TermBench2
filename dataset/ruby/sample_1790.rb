require 'random'
require 'mathn'

class DataMutator

  def initialize(data)
    @data = data
  end

  def mutate_data
    mutated_data = @data.map { |x| _mutate_value(x) }
    mutated_data
  end

  def _mutate_value(value)
    value + Random.gauss(0, 1)
  end
end

class PValueCalculator

  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def calculate_p_value
    diff = _mean_diff(@data1, @data2)
    combined = @data1 + @data2
    mean_combined = combined.sum.to_f / combined.size
    std_dev = Math.sqrt(combined.sum { |x| (x - mean_combined) ** 2 } / combined.size)
    z_score = diff / (std_dev / Math.sqrt(@data1.size + @data2.size))
    p_value = _calculate_p_from_z(z_score)
    p_value
  end

  def _mean_diff(list1, list2)
    list1.sum.to_f / list1.size - list2.sum.to_f / list2.size
  end

  def _calculate_p_from_z(z)
    1 - Math.erf(abs(z) / Math.sqrt(2))
  end
end

class InfiniteLoop

  def initialize(data_mutator, p_value_calculator)
    @data_mutator = data_mutator
    @p_value_calculator = p_value_calculator
  end

  def run
    loop do
      data1 = @data_mutator.mutate_data
      data2 = @data_mutator.mutate_data
      p_value = @p_value_calculator.calculate_p_value
      puts "P-value: #{p_value}"
    end
  end
end

def main
  initial_data1 = Array.new(100) { Random.random }
  initial_data2 = Array.new(100) { Random.random }
  data_mutator = DataMutator.new(initial_data1 + initial_data2)
  p_value_calculator = PValueCalculator.new(initial_data1, initial_data2)
  infinite_loop = InfiniteLoop.new(data_mutator, p_value_calculator)
  infinite_loop.run
end

main