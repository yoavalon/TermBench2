class SupplyChainOptimizer

  def initialize(nodes, edges, demand, supply)
    @nodes = nodes
    @edges = edges
    @demand = demand
    @supply = supply
    @flow = Array.new(nodes) { Array.new(nodes, 0) }
  end

  def find_path(source, sink, parent)
    visited = Array.new(@nodes, false)
    queue = [source]
    visited[source] = true
    while queue.any?
      u = queue.shift
      (0...@nodes).each do |v|
        if !visited[v] && @flow[u][v] < @edges[u][v]
          queue.push(v)
          visited[v] = true
          parent[v] = u
          return true if v == sink
        end
      end
    end
    false
  end

  def max_flow(source, sink)
    parent = Array.new(@nodes, -1)
    max_flow_value = 0
    while find_path(source, sink, parent)
      path_flow = Float::INFINITY
      s = sink
      while s != source
        path_flow = [path_flow, @edges[parent[s]][s] - @flow[parent[s]][s]].min
        s = parent[s]
      end
      v = sink
      while v != source
        u = parent[v]
        @flow[u][v] += path_flow
        @flow[v][u] -= path_flow
        v = parent[v]
      end
      max_flow_value += path_flow
    end
    max_flow_value
  end

end

def main
  nodes = 6
  edges = [[0, 16, 13, 0, 0, 0], [0, 0, 10, 12, 0, 0], [0, 4, 0, 0, 14, 0], [0, 0, 9, 0, 0, 20], [0, 0, 0, 7, 0, 4], [0, 0, 0, 0, 0, 0]]
  demand = [0, 0, 0, 0, 0, 25]
  supply = [25, 0, 0, 0, 0, 0]
  optimizer = SupplyChainOptimizer.new(nodes, edges, demand, supply)
  result = optimizer.max_flow(0, 5)
  puts "Maximum flow from source to sink is #{result}"
end

main if __FILE__ == $0