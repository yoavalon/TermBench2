require 'matrix'

class DigitalFilter
  def initialize(coefficients)
    @a = coefficients['a']
    @b = coefficients['b']
    @x = Array.new(@a.length - 1, 0)
    @y = Array.new(@b.length - 1, 0)
  end

  def process(sample)
    @x = [@x[1..-1], sample].flatten
    output = @b.dot(@x) - @a[1..-1].dot(@y)
    @y = [@y[1..-1], output].flatten
    return output
  end
end

class SignalGenerator
  def initialize(frequency, sample_rate, duration)
    @frequency = frequency
    @sample_rate = sample_rate
    @duration = duration
  end

  def generate
    t = Array.new(@sample_rate * @duration) { |i| i.to_f / @sample_rate }
    return t.map { |x| Math.sin(2 * Math::PI * @frequency * x) }
  end
end

def filter_signal(signal, coefficients, sample_rate, duration)
  filter = DigitalFilter.new(coefficients)
  filtered_signal = []
  signal.each do |sample|
    filtered_signal << filter.process(sample)
  end
  return Vector.elements(filtered_signal).to_a
end

def main
  coefficients = {'a' => [1, -0.9], 'b' => [0.5, 0.5]}
  generator = SignalGenerator.new(frequency: 5, sample_rate: 1000, duration: 1)
  signal = generator.generate
  filtered_signal = filter_signal(signal, coefficients, 1000, 1)
  puts filtered_signal.inspect
end

main