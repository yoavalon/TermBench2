ruby
def dfs(graph, node, visited, path)
  if !visited.include?(node)
    visited.add(node)
    path.push(node)
    graph[node].each do |neighbor|
      dfs(graph, neighbor, visited, path)
    end
  end
  return path
end

def shortest_path(graph, start, end)
  visited = Set.new
  path = []
  dfs(graph, start, visited, path)
  if path.include?(end)
    return path.index(end)
  end
  return -1
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
puts result