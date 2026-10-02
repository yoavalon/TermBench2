class DataProcessor
  def initialize(data)
    @data = data
  end

  def process_data
    processed = []
    @data.each do |item|
      processed << adjust_precision(item)
    end
    processed
  end

  def adjust_precision(value)
    value.round(5)
  end
end

class SupplyChainOptimizer
  def initialize(processed_data)
    @processed_data = processed_data
  end

  def optimize
    optimized_data = []
    @processed_data.each do |item|
      optimized_data << calculate_cost(item)
    end
    optimized_data
  end

  def calculate_cost(item)
    item * 1.05
  end
end

class ResultCompiler
  def initialize(optimized_data)
    @optimized_data = optimized_data
  end

  def compile_results
    result = {}
    @optimized_data.each_with_index do |item, index|
      result[index] = item
    end
    result
  end
end

def main
  raw_data = [100.123456, 200.654321, 300.987654, 400.135792, 500.24681]
  processor = DataProcessor.new(raw_data)
  processed_data = processor.process_data
  optimizer = SupplyChainOptimizer.new(processed_data)
  optimized_data = optimizer.optimize
  compiler = ResultCompiler.new(optimized_data)
  results = compiler.compile_results
  puts results
end

main