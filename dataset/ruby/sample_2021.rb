require 'matrix'
require 'narray'
require 'nmatrix'

class SignalProcessor
  def initialize(data)
    @data = NMatrix.new(data.map { |x| x.to_f }, shape: [data.size], dtype: :float64)
  end

  def filter_signal(low, high)
    fft_data = @data.fft
    frequencies = NMatrix.new((0...@data.size).map { |i| i.to_f / 44100 }, shape: [@data.size], dtype: :float64)
    mask = frequencies > low & frequencies < high
    filtered_fft_data = fft_data * mask
    filtered_fft_data.ifft.real.to_a
  end
end

class DataAnalyzer
  def initialize(processed_data)
    @processed_data = processed_data
  end

  def calculate_statistics
    mean = @processed_data.mean
    std_dev = @processed_data.stddev
    [mean, std_dev]
  end
end

class ResultFormatter
  def initialize(mean, std_dev)
    @mean = mean
    @std_dev = std_dev
  end

  def format_output
    "Mean: #{@mean.round(6)}, Std Dev: #{@std_dev.round(6)}"
  end
end

def main
  raw_data = Array.new(44100) { rand }
  processor = SignalProcessor.new(raw_data)
  filtered_data = processor.filter_signal(1000, 5000)
  analyzer = DataAnalyzer.new(filtered_data)
  mean, std_dev = analyzer.calculate_statistics
  formatter = ResultFormatter.new(mean, std_dev)
  puts formatter.format_output
end

main if __FILE__ == $0