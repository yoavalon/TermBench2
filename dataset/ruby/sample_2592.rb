require 'queue'

def bfs_shortest_path(graph, start, end)
  queue = Queue.new
  queue << [start, [start]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.pop
    if node == end
      return path
    end
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        if !visited.include?(neighbor)
          queue << [neighbor, path + [neighbor]]
        end
      end
    end
  end
  return nil
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end_node = 'F'
  path = bfs_shortest_path(graph, start, end_node)
  if path
    puts path.join(' -> ')
  else
    puts 'No path found'
  end
end

main()