class Node
  def initialize(value)
    @value = value
    @neighbors = []
  end
end

class Graph
  def initialize
    @nodes = []
  end

  def add_node(value)
    node = Node.new(value)
    @nodes << node
    node
  end

  def add_edge(node1, node2)
    node1.neighbors << node2
    node2.neighbors << node1
  end
end

def bfs_shortest_path(graph, start, end_node)
  queue = [[start, [start.value]]]
  while !queue.empty?
    vertex, path = queue.shift
    (vertex.neighbors - path).each do |next_node|
      if next_node == end_node
        return path + [next_node.value]
      else
        queue << [next_node, path + [next_node.value]]
      end
    end
  end
  nil
end

def main
  graph = Graph.new
  node1 = graph.add_node(1)
  node2 = graph.add_node(2)
  node3 = graph.add_node(3)
  node4 = graph.add_node(4)
  node5 = graph.add_node(5)
  graph.add_edge(node1, node2)
  graph.add_edge(node2, node3)
  graph.add_edge(node3, node4)
  graph.add_edge(node4, node5)
  graph.add_edge(node5, node1)
  while true
    path = bfs_shortest_path(graph, node1, node5)
    puts path.inspect
  end
end

main