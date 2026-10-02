require 'numo/narray'

class SignalProcessor

  def initialize(data)
    @data = Numo::DFloat[data]
  end

  def apply_filter(kernel)
    result = Numo::NArray.convolve(@data, Numo::NArray[kernel], mode: :same)
    result
  end

  def normalize(data)
    min_val = data.min
    max_val = data.max
    normalized = (data - min_val) / (max_val - min_val)
    normalized
  end

end

class SequenceGenerator

  def initialize(length)
    @length = length
  end

  def generate_sine_wave(frequency, amplitude, phase)
    t = Numo::DFloat.linspace(0, 1, @length, endpoint: false)
    wave = amplitude * Numo::DFloat.sin(2 * Math::PI * frequency * t + phase)
    wave
  end

end

class Analysis

  def initialize(processed_data)
    @data = processed_data
  end

  def calculate_fft
    fft_result = Numo::NArray.fft(@data)
    fft_result
  end

  def find_peak_frequency(fft_result)
    freqs = Numo::NArray.fft.fftfreq(fft_result.size)
    peak_idx = fft_result.abs.argmax
    peak_freq = freqs[peak_idx]
    peak_freq
  end

end

def main
  length = 1024
  generator = SequenceGenerator.new(length)
  signal = generator.generate_sine_wave(frequency: 5, amplitude: 1, phase: 0)
  processor = SignalProcessor.new(signal)
  kernel = [0.25, 0.5, 0.25]
  filtered_data = processor.apply_filter(kernel)
  normalized_data = processor.normalize(filtered_data)
  analysis = Analysis.new(normalized_data)
  fft_result = analysis.calculate_fft
  peak_frequency = analysis.find_peak_frequency(fft_result)
  puts "Peak Frequency: #{peak_frequency}"
end

main if __FILE__ == $0