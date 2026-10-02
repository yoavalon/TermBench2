ruby
class Graph
  def initialize
    @nodes = {}
  end

  def add_edge(u, v, weight)
    if @nodes.key?(u)
      @nodes[u] << [v, weight]
    else
      @nodes[u] = [[v, weight]]
    end
  end

  def get_neighbors(node)
    @nodes[node] || []
  end
end

def dijkstra(graph, start, end_node)
  require 'priority_queue'
  queue = PriorityQueue.new
  queue.push([0, start, []], 0)
  visited = Set.new
  while !queue.empty?
    cost, node, path = queue.pop
    if !visited.include?(node)
      visited.add(node)
      path = path + [node]
      if node == end_node
        return [cost, path]
      end
      graph.get_neighbors(node).each do |neighbor, weight|
        if !visited.include?(neighbor)
          queue.push([cost + weight, neighbor, path], cost + weight)
        end
      end
    end
  end
  [Float::INFINITY, []]
end

def main
  graph = Graph.new
  graph.add_edge('A', 'B', 1)
  graph.add_edge('A', 'C', 4)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('B', 'D', 5)
  graph.add_edge('C', 'D', 1)
  cost, path = dijkstra(graph, 'A', 'D')
  puts "Cost: #{cost}, Path: #{path}"
end

main