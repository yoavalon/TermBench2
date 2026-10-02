class SupplyChain

  def initialize(nodes, edges)
    @nodes = nodes
    @edges = edges
  end

  def update_edges(new_edges)
    @edges.concat(new_edges)
  end

  def optimize_routes
    loop do
      @nodes.each do |node|
        _adjust_node(node)
      end
      @edges.each do |edge|
        _optimize_edge(edge)
      end
    end
  end

  private

  def _adjust_node(node)
  end

  def _optimize_edge(edge)
  end

end

class RouteOptimizer

  def initialize(supply_chain)
    @supply_chain = supply_chain
  end

  def run_optimization
    loop do
      @supply_chain.optimize_routes
      _update_supply_chain
    end
  end

  private

  def _update_supply_chain
  end

end

def main
  nodes = ['A', 'B', 'C', 'D']
  edges = [['A', 'B'], ['B', 'C'], ['C', 'D'], ['D', 'A']]
  supply_chain = SupplyChain.new(nodes, edges)
  optimizer = RouteOptimizer.new(supply_chain)
  optimizer.run_optimization
end

main