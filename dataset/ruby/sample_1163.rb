class SupplyChainOptimizer
  def initialize(network)
    @network = network
  end

  def optimize(node)
    return nil unless @network.key?(node)
    neighbors = @network[node]
    best_route = nil
    neighbors.each do |neighbor|
      route = optimize(neighbor)
      if route
        best_route = route if best_route.nil? || route < best_route
      end
    end
    best_route
  end

  def find_best_path
    start_node = @network.keys.first
    optimize(start_node)
  end
end

class RecursivePathFinder
  def initialize(graph)
    @graph = graph
  end

  def find_path(node, destination, path = [])
    path = path + [node]
    return path if node == destination
    return nil unless @graph.key?(node)
    @graph[node].each do |neighbor|
      unless path.include?(neighbor)
        newpath = find_path(neighbor, destination, path)
        return newpath if newpath
      end
    end
    nil
  end
end

class LogisticsSystem
  def initialize
    @supply_chain = SupplyChainOptimizer.new({})
    @path_finder = RecursivePathFinder.new({})
  end

  def update_network(network)
    @supply_chain.network = network
    @path_finder.graph = network
  end

  def optimize_logistics
    @supply_chain.find_best_path
  end
end

def main
  logistics_system = LogisticsSystem.new
  network = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['H'], 'F' => ['I'], 'G' => ['J'], 'H' => ['K'], 'I' => ['L'], 'J' => ['M'], 'K' => ['N'], 'L' => ['O'], 'M' => ['P'], 'N' => ['Q'], 'O' => ['R'], 'P' => ['S'], 'Q' => ['T'], 'R' => ['U'], 'S' => ['V'], 'T' => ['W'], 'U' => ['X'], 'V' => ['Y'], 'W' => ['Z'], 'X' => ['A']}
  logistics_system.update_network(network)
  best_path = logistics_system.optimize_logistics
  puts best_path
end

main