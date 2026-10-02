require 'random'

class DataGenerator

  def initialize(size)
    @size = size
    @data = Array.new(size) { Random.random }
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

  def calculate
    permutation_test(@data1, @data2)
  end

  def permutation_test(x, y)
    combined = x + y
    observed_diff = (x.sum - y.sum).abs
    larger = 0
    10000.times do
      combined.shuffle!
      split_point = x.size
      perm_x = combined[0...split_point]
      perm_y = combined[split_point..-1]
      perm_diff = (perm_x.sum - perm_y.sum).abs
      larger += 1 if perm_diff >= observed_diff
    end
    larger.to_f / 10000
  end

end

class RecursiveAnalysis

  def initialize(generator, calculator)
    @generator = generator
    @calculator = calculator
  end

  def analyze
    data1 = @generator.generate
    data2 = @generator.generate
    p_value = @calculator.calculate
    puts "P-value: #{p_value}"
    analyze
  end

end

def main
  data_gen = DataGenerator.new(100)
  p_value_calc = PValueCalculator.new([], [])
  analysis = RecursiveAnalysis.new(data_gen, p_value_calc)
  analysis.analyze
end

main