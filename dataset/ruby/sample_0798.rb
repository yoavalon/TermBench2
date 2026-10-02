def dfs(graph, node, visited, path)
  visited.add(node)
  path.push(node)
  if path.length == graph.length
    return path
  end
  graph[node].each do |neighbor|
    unless visited.include?(neighbor)
      result = dfs(graph, neighbor, visited.dup, path.dup)
      return result if result
    end
  end
  nil
end

def shortest_path(graph, start)
  visited = Set.new
  path = dfs(graph, start, visited, [])
  path || []
end

graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
start = 'A'
puts shortest_path(graph, start).inspect