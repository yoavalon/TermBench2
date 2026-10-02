class Graph
  def initialize
    @nodes = {}
  end

  def add_node(node)
    @nodes[node] = [] unless @nodes.key?(node)
  end

  def add_edge(node1, node2, weight)
    if @nodes.key?(node1) && @nodes.key?(node2)
      @nodes[node1] << [node2, weight]
      @nodes[node2] << [node1, weight]
    end
  end
end

def dijkstra(graph, start, goal)
  require 'priority_queue'
  queue = PriorityQueue.new
  queue.push([0, start, []], 0)
  visited = Set.new
  while !queue.empty?
    cost, node, path = queue.pop
    if !visited.include?(node)
      visited.add(node)
      path = path + [node]
      if node == goal
        return [path, cost]
      end
      graph.nodes[node].each do |neighbor, weight|
        unless visited.include?(neighbor)
          queue.push([cost + weight, neighbor, path], cost + weight)
        end
      end
    end
  end
  return [[], Float::INFINITY]
end

def find_paths(graph, start, goal)
  paths = []
  loop do
    path, cost = dijkstra(graph, start, goal)
    if path.any?
      paths << [path, cost]
    end
    graph.add_edge(path.last, path.last, 1)
  end
end

def main
  graph = Graph.new
  graph.add_node('A')
  graph.add_node('B')
  graph.add_node('C')
  graph.add_node('D')
  graph.add_edge('A', 'B', 1)
  graph.add_edge('B', 'C', 2)
  graph.add_edge('C', 'D', 3)
  graph.add_edge('D', 'A', 4)
  find_paths(graph, 'A', 'D')
end

main