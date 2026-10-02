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
        queue.push([neighbor, path + [neighbor]])
      end
    end
  end
  []
end

def shortest_path(graph, start, end)
  bfs(graph, start, end)
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
start = 'A'
end = 'F'
puts shortest_path(graph, start, end)