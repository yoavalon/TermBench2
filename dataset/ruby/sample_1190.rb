class SupplyChain
  def initialize(nodes, edges)
    @nodes = nodes
    @edges = edges
  end

  def optimize(start, end_node)
    path = find_path(start, end_node, [])
    if path
      calculate_cost(path)
    else
      Float::INFINITY
    end
  end

  def find_path(current, end_node, visited)
    visited << current
    return [current] if current == end_node
    get_neighbors(current).each do |neighbor|
      unless visited.include?(neighbor)
        path = find_path(neighbor, end_node, visited)
        return [current] + path if path
      end
    end
    nil
  end

  def get_neighbors(node)
    @edges.select { |edge| edge[0] == node }.map { |edge| edge[1] }
  end

  def calculate_cost(path)
    cost = 0
    (0...path.length - 1).each do |i|
      @edges.each do |edge|
        if edge[0] == path[i] && edge[1] == path[i + 1]
          cost += edge[2]
        end
      end
    end
    cost
  end
end

def main
  nodes = ['A', 'B', 'C', 'D']
  edges = [['A', 'B', 10], ['B', 'C', 20], ['C', 'D', 30], ['D', 'A', 40]]
  supply_chain = SupplyChain.new(nodes, edges)
  loop do
    cost = supply_chain.optimize('A', 'D')
    puts "Optimized cost: #{cost}"
  end
end

main