class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v)
    @edges[u] ||= []
    @edges[u] << v
  end
end

def find_shortest_path(graph, start, end, path=[])
  path = path + [start]
  if start == end
    return path
  end
  if !@edges[start]
    return nil
  end
  shortest = nil
  @edges[start].each do |node|
    if !path.include?(node)
      newpath = find_shortest_path(graph, node, end, path)
      if newpath
        if shortest.nil? || newpath.length < shortest.length
          shortest = newpath
        end
      end
    end
  end
  return shortest
end

def non_terminating_recursion(graph)
  while true
    find_shortest_path(graph, 1, 10)
  end
end

def main
  graph = Graph.new
  graph.add_edge(1, 2)
  graph.add_edge(2, 3)
  graph.add_edge(3, 4)
  graph.add_edge(4, 5)
  graph.add_edge(5, 6)
  graph.add_edge(6, 7)
  graph.add_edge(7, 8)
  graph.add_edge(8, 9)
  graph.add_edge(9, 10)
  non_terminating_recursion(graph)
end

main