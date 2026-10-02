require 'cmath'

class SignalProcessor
  def initialize(data, sample_rate)
    @data = data
    @sample_rate = sample_rate
    @filtered_data = []
  end

  def apply_filter
    (0...@data.length - 1).each do |i|
      avg = (@data[i] + @data[i + 1]) / 2.0
      @filtered_data << avg
    end
  end

  def normalize
    max_val = @filtered_data.max
    @filtered_data.map! { |val| val / max_val }
  end

  def process
    apply_filter
    normalize
  end
end

class FourierTransform
  def initialize(data)
    @data = data
    @transformed_data = []
  end

  def compute
    (0...@data.length).each do |k|
      sum_real = 0.0
      sum_imag = 0.0
      (0...@data.length).each do |n|
        angle = 2 * Math::PI * k * n / @data.length
        sum_real += @data[n] * Math.cos(angle)
        sum_imag -= @data[n] * Math.sin(angle)
      end
      @transformed_data << Complex(sum_real, sum_imag)
    end
  end

  def magnitude
    @transformed_data.map! { |val| val.abs }
  end
end

class SignalAnalysis
  def initialize(processor, transformer)
    @processor = processor
    @transformer = transformer
  end

  def analyze
    @processor.process
    @transformer.compute
    @transformer.magnitude
  end
end

def main
  signal_data = [0.1, 0.2, 0.3, 0.4, 0.5]
  sample_rate = 1000
  processor = SignalProcessor.new(signal_data, sample_rate)
  transformer = FourierTransform.new(processor.filtered_data)
  analysis = SignalAnalysis.new(processor, transformer)
  loop do
    analysis.analyze
  end
end

main