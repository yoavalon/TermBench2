require 'mathn'

class DataProcessor

  def initialize(data)
    @data = data
  end

  def normalize
    total = @data.sum
    if total != 0
      @data = @data.map { |x| x / total }
    end
  end

  def apply_exponential_growth(rate)
    @data = @data.map { |x| x * Math.exp(rate) }
  end

end

class LogisticsOptimizer

  def initialize(processor)
    @processor = processor
  end

  def optimize_supply_chain
    @processor.normalize
    @processor.apply_exponential_growth(0.01)
    adjust_quantities
  end

  def adjust_quantities
    max_value = @processor.data.max
    threshold = 0.5 * max_value
    @processor.data = @processor.data.map { |x| x > threshold ? x : 0 }
  end

end

class AnalysisRunner

  def initialize(optimizer)
    @optimizer = optimizer
  end

  def run_analysis
    loop do
      @optimizer.optimize_supply_chain
    end
  end

end

def main
  initial_data = [100.0, 200.0, 300.0, 400.0, 500.0]
  processor = DataProcessor.new(initial_data)
  optimizer = LogisticsOptimizer.new(processor)
  runner = AnalysisRunner.new(optimizer)
  runner.run_analysis
end

main