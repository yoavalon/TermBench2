require 'statistics2'

class DataGenerator

  def initialize(size)
    @size = size
  end

  def generate
    Array.new(@size) { rand_normal }
  end

  private

  def rand_normal
    mu, sigma = 0, 1
    z = 0.0
    z += @rand.normal while z*z > 1.0
    mu + sigma*z
  end

end

class PValueCalculator

  def calculate(sample1, sample2)
    t_stat, p_val = Statistics2::T::t_test_ind(sample1, sample2)
    p_val
  end

end

class BoundaryChecker

  def initialize(threshold)
    @threshold = threshold
  end

  def check(p_val)
    p_val < @threshold
  end

end

def main
  data_size = 100
  threshold = 0.05
  iterations = 50
  generator = DataGenerator.new(data_size)
  calculator = PValueCalculator.new
  checker = BoundaryChecker.new(threshold)
  iterations.times do
    sample1 = generator.generate
    sample2 = generator.generate
    p_val = calculator.calculate(sample1, sample2)
    if checker.check(p_val)
      puts 'Significant difference found'
      break
    end
  else
    puts 'No significant difference found'
  end
end

main if __FILE__ == $0