def bfs(graph, start, end, visited = nil)
  visited ||= Set.new
  visited.add(start)
  if start == end
    return [start]
  end
  for neighbor in graph[start]
    if !visited.include?(neighbor)
      path = bfs(graph, neighbor, end, visited)
      if path.length > 0
        return [start] + path
      end
    end
  end
  return []
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
bfs(graph, 'A', 'F')