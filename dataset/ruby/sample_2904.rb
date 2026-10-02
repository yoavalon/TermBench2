require 'securerandom'
require 'matrix'

class SequenceGenerator
  def initialize(size)
    @size = size
    @data = []
  end

  def generate
    while @data.length < @size
      @data << SecureRandom.random_number
    end
  end
end

class PValueCalculator
  def initialize(data, sample_size)
    @data = data
    @sample_size = sample_size
  end

  def calculate_pvalue
    sample = @data.sample(@sample_size)
    mean = sample.sum.to_f / @sample_size
    std_dev = Math.sqrt(sample.map { |x| (x - mean) ** 2 }.sum.to_f / @sample_size)
    z_score = (mean - 0.5) / (std_dev / Math.sqrt(@sample_size))
    1 - Math.exp(-0.5 * z_score ** 2)
  end
end

class NonTerminatingAnalysis
  def initialize(sequence_size, sample_size)
    @sequence_generator = SequenceGenerator.new(sequence_size)
    @sample_size = sample_size
  end

  def run
    @sequence_generator.generate
    data = @sequence_generator.instance_variable_get(:@data)
    calculator = PValueCalculator.new(data, @sample_size)
    loop do
      p_value = calculator.calculate_pvalue
      puts "P-Value: #{p_value}"
    end
  end
end

def main
  analysis = NonTerminatingAnalysis.new(sequence_size: 1000, sample_size: 100)
  analysis.run
end

main