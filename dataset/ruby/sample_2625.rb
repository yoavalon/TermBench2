class SequenceGenerator
  def initialize(start, end)
    @start = start
    @end = end
  end

  def generate_sequence
    (@start..@end).to_a
  end
end

class OptimizationModel
  def initialize(sequence)
    @sequence = sequence
  end

  def calculate_optimal_solution
    max_value = @sequence.max
    min_value = @sequence.min
    (max_value + min_value) / 2.0
  end
end

class ResultAnalyzer
  def initialize(optimal_value)
    @optimal_value = optimal_value
  end

  def analyze_result
    if @optimal_value > 50
      'High efficiency'
    elsif @optimal_value > 25
      'Moderate efficiency'
    else
      'Low efficiency'
    end
  end
end

def main
  start = 1
  end = 100
  generator = SequenceGenerator.new(start, end)
  sequence = generator.generate_sequence
  model = OptimizationModel.new(sequence)
  optimal_value = model.calculate_optimal_solution
  analyzer = ResultAnalyzer.new(optimal_value)
  result = analyzer.analyze_result
  puts result
end

main if __FILE__ == $0