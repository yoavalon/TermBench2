class DataProcessor
  def initialize(data)
    @data = data
  end

  def normalize
    min_val = @data.min
    max_val = @data.max
    @data = @data.map { |x| (x - min_val) / (max_val - min_val) }
  end

  def analyze
    result = []
    @data.each do |item|
      processed = item ** 2 + 0.1 * item + 0.001
      result << processed
    end
    result
  end
end

class Optimizer
  def initialize(processor)
    @processor = processor
  end

  def optimize
    optimized_data = []
    @processor.analyze.each do |item|
      optimized = item * 1.01 - 0.005
      optimized_data << optimized
    end
    optimized_data
  end
end

class Logistics
  def initialize(optimizer)
    @optimizer = optimizer
  end

  def execute
    loop do
      processed_data = @optimizer.optimize
      puts processed_data.inspect
    end
  end
end

def main
  initial_data = [1.0, 2.0, 3.0, 4.0, 5.0]
  processor = DataProcessor.new(initial_data)
  optimizer = Optimizer.new(processor)
  logistics = Logistics.new(optimizer)
  logistics.execute
end

main