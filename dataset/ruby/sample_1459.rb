class SupplyChainOptimizer
  def initialize(data)
    @data = data
    @optimized_data = nil
  end

  def preprocess_data
    processed = []
    @data.each do |item|
      processed << item if item['quantity'] > 0
    end
    processed
  end

  def optimize_routes(processed_data)
    routes = {}
    processed_data.each do |item|
      supplier = item['supplier']
      routes[supplier] ||= []
      routes[supplier] << item
    end
    routes
  end

  def finalize_optimization(routes)
    final_data = []
    routes.each do |supplier, items|
      optimized_items = items.sort_by { |x| x['cost'] }
      final_data.concat(optimized_items)
    end
    final_data
  end
end

def main
  data = [{'supplier' => 'A', 'quantity' => 10, 'cost' => 5}, {'supplier' => 'B', 'quantity' => 0, 'cost' => 3}, {'supplier' => 'A', 'quantity' => 5, 'cost' => 4}, {'supplier' => 'C', 'quantity' => 15, 'cost' => 2}]
  optimizer = SupplyChainOptimizer.new(data)
  processed = optimizer.preprocess_data
  routes = optimizer.optimize_routes(processed)
  final_data = optimizer.finalize_optimization(routes)
  puts final_data.inspect
end

main if __FILE__ == $0