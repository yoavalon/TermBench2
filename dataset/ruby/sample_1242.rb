def graph_traversal(graph, start, end)
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
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  puts graph_traversal(graph, 'A', 'F')
end

main