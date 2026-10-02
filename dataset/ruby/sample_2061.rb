class Simulation

  def initialize(a, b, c)
    @a = a
    @b = b
    @c = c
  end

  def calculate(x)
    @a * x ** 2 + @b * x + @c
  end

end

class PrecisionAnalyzer

  def initialize(simulation)
    @simulation = simulation
  end

  def analyze(x_values)
    results = []
    x_values.each do |x|
      result = @simulation.calculate(x)
      results << result
    end
    results
  end

end

class DataProcessor

  def initialize(analyzer)
    @analyzer = analyzer
  end

  def process(x_values)
    raw_data = @analyzer.analyze(x_values)
    processed_data = format_data(raw_data)
    processed_data
  end

  def format_data(data)
    formatted = []
    data.each do |value|
      formatted << value.round(5)
    end
    formatted
  end

end

def main
  sim = Simulation.new(2.0, 3.0, 1.0)
  analyzer = PrecisionAnalyzer.new(sim)
  processor = DataProcessor.new(analyzer)
  x_values = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
  processed_results = processor.process(x_values)
  processed_results.each_with_index do |value, i|
    puts "X: #{x_values[i]}, Result: #{value}"
  end
end

main