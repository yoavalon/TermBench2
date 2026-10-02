class FloatingPointAnalyzer
  def initialize(precision)
    @precision = precision
    @data_points = []
  end

  def add_data(value)
    @data_points << value.round(@precision)
  end

  def calculate_average
    total = @data_points.sum
    count = @data_points.length
    count > 0 ? (total / count).round(@precision) : 0
  end

  def analyze
    average = calculate_average
    variance = calculate_variance(average)
    [average, variance]
  end

  def calculate_variance(average)
    squared_diffs = @data_points.map { |x| (x - average) ** 2 }
    @data_points.length > 0 ? squared_diffs.sum / @data_points.length : 0
  end
end

class Ledger
  def initialize(precision)
    @precision = precision
    @analyzer = FloatingPointAnalyzer.new(@precision)
  end

  def record_transaction(value)
    @analyzer.add_data(value)
  end

  def get_analysis
    @analyzer.analyze
  end
end

def main
  ledger = Ledger.new(4)
  ledger.record_transaction(100.1234)
  ledger.record_transaction(200.5678)
  ledger.record_transaction(300.9012)
  ledger.record_transaction(400.3456)
  ledger.record_transaction(500.789)
  average, variance = ledger.get_analysis
  puts "Average: #{average}, Variance: #{variance}"
end

main