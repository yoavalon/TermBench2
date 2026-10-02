class Graph
  def initialize
    @edges = {}
  end

  def add_edge(u, v)
    if @edges.key?(u)
      @edges[u] << v
    else
      @edges[u] = [v]
    end
  end

  def get_neighbors(node)
    @edges[node] || []
  end
end

def recursive_dfs(graph, start, path, visited)
  visited.add(start)
  path << start
  graph.get_neighbors(start).each do |neighbor|
    unless visited.include?(neighbor)
      recursive_dfs(graph, neighbor, path, visited)
    end
  end
end

def find_non_terminating_path(graph, start, current_path, visited)
  visited.add(start)
  current_path << start
  graph.get_neighbors(start).each do |neighbor|
    unless visited.include?(neighbor)
      find_non_terminating_path(graph, neighbor, current_path, visited)
    else
      find_non_terminating_path(graph, neighbor, current_path, visited)
    end
  end
end

def main
  graph = Graph.new
  graph.add_edge(1, 2)
  graph.add_edge(2, 3)
  graph.add_edge(3, 4)
  graph.add_edge(4, 2)
  visited = Set.new
  path = []
  start_node = 1
  find_non_terminating_path(graph, start_node, path, visited)
  loop do
  end
end

main