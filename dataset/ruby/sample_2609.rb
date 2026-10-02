require 'matrix'

class SequenceGenerator
  def initialize(length)
    @length = length
  end

  def generate
    sequence = Array.new(@length, 0.0)
    (1...@length).each do |i|
      sequence[i] = sequence[i - 1] + 0.5
    end
    sequence
  end
end

class FilterApplier
  def initialize(coefficients)
    @coefficients = coefficients
  end

  def apply(sequence)
    filtered_sequence = sequence.convolve(@coefficients)
    filtered_sequence
  end
end

class SignalProcessor
  def initialize(generator, filter)
    @generator = generator
    @filter = filter
  end

  def process
    sequence = @generator.generate
    filtered_sequence = @filter.apply(sequence)
    filtered_sequence
  end
end

def main
  length = 100
  coefficients = [0.25, 0.5, 0.25]
  generator = SequenceGenerator.new(length)
  filter_applier = FilterApplier.new(coefficients)
  processor = SignalProcessor.new(generator, filter_applier)
  result = processor.process
  puts result.inspect
end

main if __FILE__ == $0