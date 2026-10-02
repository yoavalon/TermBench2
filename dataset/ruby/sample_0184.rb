require 'set'

def bfs(graph, start, end)
  queue = [[start, 0]]
  visited = Set.new
  while queue.any?
    node, dist = queue.shift
    return dist if node == end
    unless visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue << [neighbor, dist + 1]
      end
    end
  end
  -1
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end_node = 'F'
  puts bfs(graph, start, end_node)
end

main