def bfs(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    if !visited.include?(node)
      visited.add(node)
      if node == end
        return path
      end
      graph[node].each do |neighbor|
        if !visited.include?(neighbor)
          queue.push([neighbor, path + [neighbor]])
        end
      end
    end
  end
end

def find_shortest_path(graph, start, end)
  path = bfs(graph, start, end)
  if path
    return path.length - 1
  else
    return -1
  end
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end_node = 'F'
  result = find_shortest_path(graph, start, end_node)
  puts result
end

main