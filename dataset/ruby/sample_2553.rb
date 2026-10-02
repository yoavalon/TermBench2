def bfs(graph, start, end)
  queue = [[start, [start]]]
  while queue.any?
    node, path = queue.shift
    graph[node].each do |neighbor|
      if neighbor == end
        return path + [neighbor]
      elsif !path.include?(neighbor)
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
  nil
end

def find_shortest_path(graph, start, end)
  bfs(graph, start, end)
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end = 'F'
  path = find_shortest_path(graph, start, end)
  if path
    puts path.join(' -> ')
  else
    puts 'No path found'
  end
end

main