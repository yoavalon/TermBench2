def dfs(graph, start, end, path, visited)
  path.push(start)
  visited.add(start)
  return path if start == end
  graph[start].each do |neighbor|
    unless visited.include?(neighbor)
      result = dfs(graph, neighbor, end, path.clone, visited)
      return result if result
    end
  end
  nil
end

def find_shortest_path(graph, start, end)
  dfs(graph, start, end, [], Set.new)
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
path = find_shortest_path(graph, 'A', 'F')
if path
  puts 'Path found:', path
else
  puts 'No path found'
end