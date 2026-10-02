require 'matrix'

class Filter
  def initialize(coefficients)
    @coeffs = coefficients
    @state = Array.new(@coeffs.size - 1, 0)
  end

  def apply(signal)
    output = signal.convolve(@coeffs)[0...-(@coeffs.size - 1)]
    update_state(signal, output)
    output
  end

  def update_state(signal, output)
    new_state = signal[-(@coeffs.size - 1)..-1] + output
    @state = new_state[-(@coeffs.size - 1)..-1]
  end
end

class BoundaryProcessor
  def initialize(filter_obj, boundary_values)
    @filter = filter_obj
    @boundaries = boundary_values
  end

  def process(data)
    filtered_data = @filter.apply(data)
    clipped_data = clip(filtered_data)
    clipped_data
  end

  def clip(data)
    data.map { |x| [x, @boundaries[0]].max }.map { |x| [x, @boundaries[1]].min }
  end
end

class DataAnalyzer
  def initialize(processor)
    @processor = processor
  end

  def analyze(input_data)
    processed_data = @processor.process(input_data)
    processed_data
  end
end

def main
  coefficients = [0.05, 0.1, 0.2, 0.1, 0.05]
  filter_obj = Filter.new(coefficients)
  boundary_values = [-1, 1]
  processor = BoundaryProcessor.new(filter_obj, boundary_values)
  analyzer = DataAnalyzer.new(processor)
  input_data = Array.new(1000) { randn }
  result = analyzer.analyze(input_data)
  puts result.inspect
end

main