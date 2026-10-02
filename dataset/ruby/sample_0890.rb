class SupplyChainOptimizer
  def initialize(nodes, edges, demand)
    @nodes = nodes
    @edges = edges
    @demand = demand
    @path = []
  end

  def optimize
    _find_path(0, 0, 0)
  end

  def _find_path(current_node, current_cost, current_demand)
    if current_node == @nodes.length - 1
      if current_demand == @demand
        @path.unshift(current_node)
        return true
      end
      return false
    end
    @edges[current_node].each do |neighbor, cost|
      if _find_path(neighbor, current_cost + cost, current_demand + 1)
        @path.unshift(current_node)
        return true
      end
    end
    return false
  end
end

class DemandBalancer
  def initialize(nodes, edges, demand)
    @optimizer = SupplyChainOptimizer.new(nodes, edges, demand)
  end

  def balance
    @optimizer.optimize
    return @optimizer.path
  end
end

def main
  nodes = [0, 1, 2, 3, 4]
  edges = {0 => [[1, 10], [2, 15]], 1 => [[3, 5]], 2 => [[3, 10]], 3 => [[4, 20]], 4 => []}
  demand = 3
  balancer = DemandBalancer.new(nodes, edges, demand)
  result = balancer.balance
  puts result
end

main if __FILE__ == $0