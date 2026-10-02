require 'set'

def bfs(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    return path if node == end
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
  []
end

def find_shortest_path(graph, start, end)
  bfs(graph, start, end)
end

if __FILE__ == $0
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start_node = 'A'
  end_node = 'F'
  path = find_shortest_path(graph, start_node, end_node)
  puts path
end