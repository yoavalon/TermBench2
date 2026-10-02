def dfs(graph, start, end, visited = nil)
  visited ||= Set.new
  visited.add(start)
  if start == end
    return [start]
  end
  for neighbor in graph[start]
    if !visited.include?(neighbor)
      path = dfs(graph, neighbor, end, visited)
      if path
        return [start] + path
      end
    end
  end
  return nil
end

def shortest_path(graph, start, end)
  path = dfs(graph, start, end)
  if path
    return path.length - 1
  end
  return -1
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['G'], 'F' => ['G'], 'G' => []}
start_node = 'A'
end_node = 'G'
result = shortest_path(graph, start_node, end_node)
puts result