require 'set'

def bfs(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    return path if node == end
    unless visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
  nil
end

def shortest_path(graph, start, end)
  bfs(graph, start, end)
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end_node = 'F'
  path = shortest_path(graph, start, end_node)
  if path
    puts 'Shortest path:', path
  else
    puts 'No path found'
  end
end

main