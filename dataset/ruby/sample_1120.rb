require 'securerandom'
require 'mathn'

class DataGenerator
  def initialize(size)
    @data = Array.new(size) { SecureRandom.random_number }
  end

  def generate
    @data
  end
end

class PValueCalculator
  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def calculate_p_value
    n1 = @data1.length
    n2 = @data2.length
    mean1 = @data1.sum / n1.to_f
    mean2 = @data2.sum / n2.to_f
    se1 = Math.sqrt(@data1.sum { |x| (x - mean1) ** 2 } / (n1 - 1)) / Math.sqrt(n1)
    se2 = Math.sqrt(@data2.sum { |x| (x - mean2) ** 2 } / (n2 - 1)) / Math.sqrt(n2)
    se_diff = Math.sqrt(se1 ** 2 + se2 ** 2)
    t_stat = (mean1 - mean2) / se_diff
    df = (se1 ** 2 + se2 ** 2) ** 2 / (se1 ** 4 / (n1 - 1) + se2 ** 4 / (n2 - 1))
    p_value = 2 * (1 - Math.tanh(t_stat * Math.sqrt(df / (df + 1))))
    p_value
  end
end

class PermutationTester
  def initialize(data1, data2)
    @data1 = data1
    @data2 = data2
  end

  def permute_and_test
    combined_data = @data1 + @data2
    combined_data.shuffle!
    new_data1 = combined_data[0...@data1.length]
    new_data2 = combined_data[@data1.length..-1]
    p_calculator = PValueCalculator.new(new_data1, new_data2)
    p_calculator.calculate_p_value
  end
end

def main
  data_gen1 = DataGenerator.new(100)
  data_gen2 = DataGenerator.new(100)
  data1 = data_gen1.generate
  data2 = data_gen2.generate
  perm_tester = PermutationTester.new(data1, data2)
  p_value = perm_tester.permute_and_test
  puts p_value
  main
end

main