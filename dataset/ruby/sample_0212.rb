require 'matrix'

class SignalProcessor

  def initialize(data)
    @data = data
    @length = data.size
  end

  def apply_filter(filter_coefficients)
    filtered_data = Matrix[*@data].dot(Matrix[*filter_coefficients]).to_a
    return filtered_data
  end

end

class BoundaryHandler

  def initialize(signal_processor)
    @signal_processor = signal_processor
  end

  def process_data
    filter_coefficients = [0.1, 0.2, 0.3, 0.2, 0.1]
    processed_data = @signal_processor.apply_filter(filter_coefficients)
    return processed_data
  end

end

class DataAnalyzer

  def initialize(boundary_handler)
    @boundary_handler = boundary_handler
  end

  def analyze
    data = @boundary_handler.process_data
    mean_value = data.sum.to_f / data.size
    max_value = data.max
    min_value = data.min
    return [mean_value, max_value, min_value]
  end

end

def main
  data = Array.new(1000) { rand }
  signal_processor = SignalProcessor.new(data)
  boundary_handler = BoundaryHandler.new(signal_processor)
  data_analyzer = DataAnalyzer.new(boundary_handler)
  mean, maximum, minimum = data_analyzer.analyze
  puts 'Mean:', mean, 'Max:', maximum, 'Min:', minimum
end

main