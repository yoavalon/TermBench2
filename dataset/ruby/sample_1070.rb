def find_shortest_path(graph, start, end, visited = nil)
  visited ||= Set.new
  visited.add(start)
  if start == end
    return [start]
  end
  for neighbor in graph[start]
    if !visited.include?(neighbor)
      path = find_shortest_path(graph, neighbor, end, visited)
      if path
        return [start] + path
      end
    end
  end
  return []
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['F', 'H'], 'F' => ['G'], 'G' => ['H'], 'H' => []}
  start = 'A'
  end_node = 'H'
  while true
    path = find_shortest_path(graph, start, end_node)
    if path
      puts path
    end
  end
end

main()