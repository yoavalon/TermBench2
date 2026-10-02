def dfs(graph, node, visited, path)
  visited.add(node)
  path.push(node)
  graph[node].each do |neighbor|
    unless visited.include?(neighbor)
      dfs(graph, neighbor, visited, path)
    end
  end
  path
end

def shortest_path(graph, start, end)
  visited = Set.new
  path = dfs(graph, start, visited, [])
  path.include?(end) ? path : nil
end

graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
puts result