def dfs(graph, node, visited, path, paths)
  visited.add(node)
  path.push(node)
  if graph[node].length == 0
    paths.push(path.dup)
  end
  graph[node].each do |neighbor|
    if !visited.include?(neighbor)
      dfs(graph, neighbor, visited, path, paths)
    end
  end
  path.pop
  visited.delete(node)
end

def shortest_path(graph, start, end)
  paths = []
  dfs(graph, start, Set.new, [], paths)
  min_length = Float::INFINITY
  best_path = nil
  paths.each do |path|
    if path.last == end && path.length < min_length
      min_length = path.length
      best_path = path
    end
  end
  best_path
end

graph = {'A' => ['B', 'C'], 'B' => ['D'], 'C' => ['D'], 'D' => []}
start_node = 'A'
end_node = 'D'
puts shortest_path(graph, start_node, end_node)