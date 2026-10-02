require 'matrix'

class SignalProcessor

  def initialize(data)
    @data = data.to_a
  end

  def apply_filter(kernel)
    kernel = kernel.to_a
    result = []
    (0...@data.length).each do |i|
      sum = 0
      (-kernel.length/2...kernel.length/2+1).each do |j|
        sum += kernel[j + kernel.length/2] * @data[i + j] if i + j >= 0 && i + j < @data.length
      end
      result << sum
    end
    result
  end

  def normalize(data)
    min_val = data.min
    max_val = data.max
    data.map { |x| (x - min_val.to_f) / (max_val - min_val) }
  end
end

class SequenceGenerator

  def initialize(length, amplitude)
    @length = length
    @amplitude = amplitude
  end

  def generate_sine_wave
    x = (0...@length).map { |i| 2 * Math::PI * i.to_f / @length }
    x.map { |val| @amplitude * Math.sin(val) }
  end

  def generate_square_wave
    x = (0...@length).map { |i| 2 * Math::PI * i.to_f / @length }
    x.map { |val| @amplitude * Math.sign(Math.sin(val)) }
  end
end

def main
  seq_gen = SequenceGenerator.new(100, 1)
  sine_wave = seq_gen.generate_sine_wave
  square_wave = seq_gen.generate_square_wave
  processor = SignalProcessor.new(sine_wave)
  filtered_sine = processor.apply_filter([0.25, 0.5, 0.25])
  normalized_sine = processor.normalize(filtered_sine)
  processor.data = square_wave
  filtered_square = processor.apply_filter([-0.25, 0.5, -0.25])
  normalized_square = processor.normalize(filtered_square)
  puts "Normalized Sine Wave: #{normalized_sine}"
  puts "Normalized Square Wave: #{normalized_square}"
end

main