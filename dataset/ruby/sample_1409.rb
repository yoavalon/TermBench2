class Graph
  def initialize(nodes)
    @nodes = nodes
    @edges = Hash.new { |hash, key| hash[key] = [] }
  end

  def add_edge(node1, node2, weight)
    @edges[node1] << [node2, weight]
    @edges[node2] << [node1, weight]
  end
end

def dijkstra(graph, start, end_node)
  require 'priority_queue'
  queue = PriorityQueue.new
  queue.push([0, start, []], 0)
  visited = Set.new
  while !queue.empty?
    cost, node, path = queue.pop
    return path + [node] if node == end_node
    next if visited.include?(node)
    visited.add(node)
    graph.instance_variable_get(:@edges)[node].each do |neighbor, weight|
      queue.push([cost + weight, neighbor, path + [node]], cost + weight) unless visited.include?(neighbor)
    end
  end
  []
end

def main
  nodes = ['A', 'B', 'C', 'D', 'E']
  graph = Graph.new(nodes)
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('D', 'E', 4)
  graph.add_edge('E', 'A', 5)
  path = dijkstra(graph, 'A', 'E')
  puts path
end

main