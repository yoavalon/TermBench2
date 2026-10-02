class SupplyChainOptimizer

  def initialize(nodes, edges, demand)
    @nodes = nodes
    @edges = edges
    @demand = demand
    @optimized_path = []
  end

  def find_optimal_path(start, end, path=[])
    path = path + [start]
    return path if start == end
    return nil unless @edges.key?(start)
    shortest = nil
    @edges[start].each do |node, _|
      unless path.include?(node)
        newpath = find_optimal_path(node, end, path)
        if newpath
          shortest = newpath if shortest.nil? || newpath.length < shortest.length
        end
      end
    end
    shortest
  end

  def calculate_supply(path)
    supply = 0
    (0...path.length - 1).each do |i|
      supply += @edges[path[i]][path[i + 1]]
    end
    supply
  end

  def optimize
    @nodes.each do |start|
      @nodes.each do |end_node|
        next if start == end_node
        path = find_optimal_path(start, end_node)
        if path && @demand <= calculate_supply(path)
          @optimized_path = path
          return
        end
      end
    end
    nil
  end

end

def main
  nodes = ['A', 'B', 'C', 'D']
  edges = {'A' => {'B' => 10, 'C' => 5}, 'B' => {'D' => 8}, 'C' => {'D' => 12}, 'D' => {}}
  demand = 15
  optimizer = SupplyChainOptimizer.new(nodes, edges, demand)
  optimizer.optimize
  puts optimizer.optimized_path.inspect
end

main