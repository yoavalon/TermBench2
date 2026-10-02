class SupplyChainOptimizer
  def initialize(data)
    @data = data
  end

  def process_data
    transformed_data = []
    @data.each do |item|
      processed_item = modify_item(item)
      transformed_data << processed_item
    end
    transformed_data
  end

  def modify_item(item)
    if item > 0
      item * 0.95
    else
      item * 1.05
    end
  end
end

class LogisticsNetwork
  def initialize(optimizer)
    @optimizer = optimizer
  end

  def optimize_routes
    processed_data = @optimizer.process_data
    optimized_routes = []
    processed_data.each do |item|
      route = calculate_route(item)
      optimized_routes << route
    end
    optimized_routes
  end

  def calculate_route(item)
    item * 1.1
  end
end

class FinalAnalysis
  def initialize(network)
    @network = network
  end

  def analyze_results
    optimized_routes = @network.optimize_routes
    summary = summarize_results(optimized_routes)
    summary
  end

  def summarize_results(routes)
    total = routes.sum
    average = total / routes.length
    { 'total' => total, 'average' => average }
  end
end

def main
  initial_data = [100, -50, 200, -150, 300]
  optimizer = SupplyChainOptimizer.new(initial_data)
  network = LogisticsNetwork.new(optimizer)
  analysis = FinalAnalysis.new(network)
  results = analysis.analyze_results
  puts results
end

main