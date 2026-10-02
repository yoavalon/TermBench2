class SequenceGenerator

  def initialize(size)
    @size = size
    @sequence = []
  end

  def generate_fibonacci
    a, b = 0, 1
    @size.times do
      @sequence << a
      a, b = b, a + b
    end
  end

  def generate_arithmetic(diff)
    @size.times do |i|
      @sequence << diff * i
    end
  end

  def generate_geometric(ratio)
    @size.times do |i|
      @sequence << ratio ** i
    end
  end

end

class DataProcessor

  def initialize(sequence)
    @sequence = sequence
  end

  def calculate_mean
    @sequence.sum.to_f / @sequence.size
  end

  def calculate_median
    sorted_seq = @sequence.sort
    mid = sorted_seq.size / 2
    sorted_seq.size.even? ? (sorted_seq[mid - 1] + sorted_seq[mid]) / 2.0 : sorted_seq[mid]
  end

  def calculate_variance
    mean = calculate_mean
    @sequence.sum { |x| (x - mean) ** 2 } / @sequence.size
  end

end

class Optimizer

  def initialize(processor)
    @processor = processor
  end

  def optimize_supply_chain
    mean = @processor.calculate_mean
    median = @processor.calculate_median
    variance = @processor.calculate_variance
    { 'mean' => mean, 'median' => median, 'variance' => variance }
  end

end

def main
  size = 10
  diff = 2
  ratio = 3
  generator = SequenceGenerator.new(size)
  generator.generate_fibonacci
  processor = DataProcessor.new(generator.sequence)
  optimizer = Optimizer.new(processor)
  result = optimizer.optimize_supply_chain
  puts result
end

main