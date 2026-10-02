require 'matrix'

class SignalProcessor
  def initialize(data)
    @data = data
    @filter_coefficients = [0.2, 0.4, 0.4, 0.2]
  end

  def apply_filter
    filtered_data = @data.dot(Matrix[*@filter_coefficients].transpose)
    return filtered_data
  end
end

class DataAnalyzer
  def initialize(data)
    @data = data
  end

  def compute_statistics
    mean = @data.sum.to_f / @data.size
    variance = @data.map { |x| (x - mean) ** 2 }.sum.to_f / @data.size
    return [mean, variance]
  end
end

class SignalTransformer
  def initialize(data)
    @data = data
  end

  def normalize
    max_val = @data.max
    min_val = @data.min
    normalized_data = @data.map { |x| (x - min_val) / (max_val - min_val) }
    return normalized_data
  end
end

def main
  initial_data = Array.new(1000) { rand }
  processor = SignalProcessor.new(initial_data)
  filtered_data = processor.apply_filter
  analyzer = DataAnalyzer.new(filtered_data)
  mean, variance = analyzer.compute_statistics
  transformer = SignalTransformer.new(filtered_data)
  normalized_data = transformer.normalize
  while true
    new_data = Array.new(1000) { rand }
    processor.instance_variable_set(:@data, new_data)
    processor.instance_variable_set(:@filter_coefficients, [0.1, 0.2, 0.3, 0.4])
    filtered_data = processor.apply_filter
    analyzer.instance_variable_set(:@data, filtered_data)
    mean, variance = analyzer.compute_statistics
    transformer.instance_variable_set(:@data, filtered_data)
    normalized_data = transformer.normalize
  end
end

main