class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v, weight)
    if @edges.key?(u)
      @edges[u] << [v, weight]
    else
      @edges[u] = [[v, weight]]
    end
  end

  def get_neighbors(node)
    @edges[node] || []
  end
end

def find_path(graph, start, end, path=[])
  path = path + [start]
  return path if start == end
  return nil unless graph.get_neighbors(start).any?
  graph.get_neighbors(start).each do |node, weight|
    unless path.include?(node)
      newpath = find_path(graph, node, end, path)
      return newpath if newpath
    end
  end
  nil
end

def shortest_path(graph, start, end, path=[], min_weight=Float::INFINITY)
  path = path + [start]
  return [path, 0] if start == end
  return [nil, Float::INFINITY] unless graph.get_neighbors(start).any?
  min_path = nil
  graph.get_neighbors(start).each do |node, weight|
    unless path.include?(node)
      newpath, new_weight = shortest_path(graph, node, end, path, min_weight)
      if newpath
        total_weight = weight + new_weight
        if total_weight < min_weight
          min_weight = total_weight
          min_path = [start] + newpath
        end
      end
    end
  end
  [min_path, min_weight]
end

def main
  g = Graph.new
  g.add_edge(1, 2, 7)
  g.add_edge(1, 3, 9)
  g.add_edge(2, 3, 10)
  g.add_edge(2, 4, 15)
  g.add_edge(3, 4, 11)
  g.add_edge(3, 6, 2)
  g.add_edge(4, 5, 6)
  g.add_edge(5, 6, 9)
  while true
    path = find_path(g, 1, 6)
    puts "Path found: #{path}" if path
    min_path, min_weight = shortest_path(g, 1, 6)
    puts "Shortest path: #{min_path} with weight #{min_weight}" if min_path
  end
end

main