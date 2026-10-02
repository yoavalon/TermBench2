class DataProcessor
  def initialize(data)
    @data = data
  end

  def preprocess
    processed_data = []
    @data.each do |item|
      processed_data << item if item > 0
    end
    processed_data
  end

  def calculate(processed_data)
    total = 0
    processed_data.each do |item|
      total += item * 2
    end
    total
  end
end

class Optimizer
  def initialize(result)
    @result = result
  end

  def optimize
    @result * 0.95
  end
end

class TerminationAnalyzer
  def initialize(optimized_result)
    @optimized_result = optimized_result
  end

  def analyze
    @optimized_result < 100
  end
end

def main
  initial_data = [10, -5, 20, 0, 15]
  processor = DataProcessor.new(initial_data)
  processed_data = processor.preprocess
  calculator = Optimizer.new(processor.calculate(processed_data))
  optimized_result = calculator.optimize
  analyzer = TerminationAnalyzer.new(optimized_result)
  analysis_result = analyzer.analyze
  puts analysis_result
end

main if __FILE__ == $0