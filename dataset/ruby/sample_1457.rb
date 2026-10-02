class DataProcessor
  def initialize(data)
    @data = data
  end

  def filter_data
    @data = @data.select { |x| x['quantity'] > 0 }
  end

  def transform_data
    @data = @data.map { |x| { 'id' => x['id'], 'value' => x['quantity'] * x['price'] } }
  end

  def aggregate_data
    total_value = @data.sum { |x| x['value'] }
    total_value
  end
end

class DataOptimizer
  def initialize(data)
    @data = data
  end

  def optimize_routes
    @data = @data.sort_by { |x| x['distance'] }
  end

  def reduce_inventory
    @data = @data.map { |x| { 'id' => x['id'], 'quantity' => x['quantity'] - 1 } }
  end
end

class DataAnalyzer
  def initialize(data)
    @data = data
  end

  def calculate_performance
    total_distance = @data.sum { |x| x['distance'] }
    total_distance
  end
end

def main
  initial_data = [{ 'id' => 1, 'quantity' => 10, 'price' => 20, 'distance' => 100 }, { 'id' => 2, 'quantity' => 5, 'price' => 30, 'distance' => 200 }, { 'id' => 3, 'quantity' => 0, 'price' => 40, 'distance' => 150 }, { 'id' => 4, 'quantity' => 8, 'price' => 25, 'distance' => 300 }]
  processor = DataProcessor.new(initial_data)
  processor.filter_data
  processor.transform_data
  total_value = processor.aggregate_data
  optimizer = DataOptimizer.new(processor.data)
  optimizer.optimize_routes
  optimizer.reduce_inventory
  analyzer = DataAnalyzer.new(optimizer.data)
  total_distance = analyzer.calculate_performance
  puts "Total Value: #{total_value}"
  puts "Total Distance: #{total_distance}"
end

main