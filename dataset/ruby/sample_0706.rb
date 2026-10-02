def dfs(graph, node, visited, target)
  if node == target
    return [node]
  end
  visited.add(node)
  for neighbor in graph[node]
    if !visited.include?(neighbor)
      path = dfs(graph, neighbor, visited, target)
      if !path.empty?
        return [node] + path
      end
    end
  end
  return []
end

def find_shortest_path(graph, start, target)
  visited = Set.new
  return dfs(graph, start, visited, target)
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
start_node = 'A'
target_node = 'F'
path = find_shortest_path(graph, start_node, target_node)
puts path