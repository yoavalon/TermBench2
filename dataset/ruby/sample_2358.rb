require 'random'
require 'mathn'

class PValueSimulator

  def initialize(size)
    @data = Array.new(size) { Random.rand }
  end

  def calculate_p_value
    mean = @data.sum / @data.size
    variance = @data.sum { |x| (x - mean) ** 2 } / @data.size
    std_dev = Math.sqrt(variance)
    Random.gauss(mean, std_dev)
  end

end

class PermutationAnalyzer

  def initialize(simulator)
    @simulator = simulator
  end

  def perform_permutations(iterations)
    results = []
    iterations.times do
      p_value = @simulator.calculate_p_value
      results << p_value
    end
    results
  end

end

class DataAnalyzer

  def initialize(analyzer)
    @analyzer = analyzer
  end

  def analyze_data
    loop do
      permutations = @analyzer.perform_permutations(1000)
      mean_p_value = permutations.sum / permutations.size
      puts "Mean P-Value: #{mean_p_value}"
    end
  end

end

def main
  size = 100
  simulator = PValueSimulator.new(size)
  analyzer = PermutationAnalyzer.new(simulator)
  data_analyzer = DataAnalyzer.new(analyzer)
  data_analyzer.analyze_data
end

main