require 'matrix'

class SignalProcessor

  def initialize(data)
    @data = data.to_a
  end

  def apply_filter(kernel)
    filtered_data = []
    data_length = @data.length
    kernel_length = kernel.length
    half_kernel = kernel_length / 2

    (0...data_length).each do |i|
      sum = 0
      (0...kernel_length).each do |j|
        sum += @data[(i - half_kernel + j) % data_length] * kernel[j]
      end
      filtered_data << sum
    end

    filtered_data
  end

  def normalize(data)
    min_val = data.min
    max_val = data.max
    if max_val == min_val
      return data
    end
    data.map { |x| (x - min_val) / (max_val - min_val) }
  end
end

class BoundaryHandler

  def initialize(processor)
    @processor = processor
  end

  def handle_edges(data, mode='reflect')
    if mode == 'reflect'
      [data.first] + data + [data.last]
    else
      data
    end
  end

  def terminate_condition(data, threshold=0.5)
    data.all? { |x| x < threshold }
  end
end

class MainController

  def initialize(signal_data)
    @signal_processor = SignalProcessor.new(signal_data)
    @boundary_handler = BoundaryHandler.new(@signal_processor)
  end

  def process_signal
    kernel = [1, 2, 1]
    data = @signal_processor.apply_filter(kernel)
    data = @boundary_handler.handle_edges(data)
    normalized_data = @signal_processor.normalize(data)

    while !@boundary_handler.terminate_condition(normalized_data)
      data = @signal_processor.apply_filter(kernel)
      data = @boundary_handler.handle_edges(data)
      normalized_data = @signal_processor.normalize(data)
    end

    normalized_data
  end
end

def main
  signal_data = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
  controller = MainController.new(signal_data)
  result = controller.process_signal
  puts result
end

main