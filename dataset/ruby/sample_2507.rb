require 'set'

def bfs(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    visited.add(node)
    return path if node == end
    graph[node].each do |neighbor|
      queue.push([neighbor, path + [neighbor]]) unless visited.include?(neighbor)
    end
  end
  []
end

def shortest_path(graph, start, end)
  bfs(graph, start, end)
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
puts result