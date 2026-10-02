class SupplyChainOptimizer

  def initialize(nodes, edges, capacity)
    @nodes = nodes
    @edges = edges
    @capacity = capacity
    @flow = Array.new(@nodes) { Array.new(@nodes, 0) }
  end

  def find_path(source, sink, parent)
    visited = Array.new(@nodes, false)
    queue = [source]
    visited[source] = true
    while !queue.empty?
      u = queue.shift
      for ind in 0...@nodes
        if !visited[ind] && @capacity[u][ind] - @flow[u][ind] > 0
          queue.push(ind)
          visited[ind] = true
          parent[ind] = u
          if ind == sink
            return true
          end
        end
      end
    end
    return false
  end

  def optimize_flow(source, sink)
    parent = Array.new(@nodes, -1)
    max_flow = 0
    while find_path(source, sink, parent)
      path_flow = Float::INFINITY
      s = sink
      while s != source
        path_flow = [path_flow, @capacity[parent[s]][s] - @flow[parent[s]][s]].min
        s = parent[s]
      end
      v = sink
      while v != source
        u = parent[v]
        @flow[u][v] += path_flow
        @flow[v][u] -= path_flow
        v = parent[v]
      end
      max_flow += path_flow
    end
    return max_flow
  end

end

def main
  nodes = 6
  edges = 7
  capacity = [[0, 16, 13, 0, 0, 0], [0, 0, 10, 12, 0, 0], [0, 4, 0, 0, 14, 0], [0, 0, 9, 0, 0, 20], [0, 0, 0, 7, 0, 4], [0, 0, 0, 0, 0, 0]]
  source = 0
  sink = 5
  optimizer = SupplyChainOptimizer.new(nodes, edges, capacity)
  result = optimizer.optimize_flow(source, sink)
  puts "The maximum possible flow is %d " % result
end

main if __FILE__ == $0