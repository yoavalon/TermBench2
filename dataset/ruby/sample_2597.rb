def find_shortest_path(graph, start, end)
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

def main
  graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
  path = find_shortest_path(graph, 'A', 'F')
  puts path
end

main