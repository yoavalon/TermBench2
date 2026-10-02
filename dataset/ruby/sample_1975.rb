require 'heap'

def dijkstra(graph, start, end)
  queue = Heap.new
  queue.push([0, start, []])
  visited = Set.new
  while !queue.empty?
    cost, node, path = queue.pop
    if !visited.include?(node)
      visited.add(node)
      path = path + [node]
      if node == end
        return [cost, path]
      end
      graph[node].each do |neighbor, weight|
        if !visited.include?(neighbor)
          queue.push([cost + weight, neighbor, path])
        end
      end
    end
  end
  return [Float::INFINITY, []]
end

def main
  graph = {'A' => [['B', 1.5], ['C', 2.3]], 'B' => [['C', 0.9], ['D', 3.2]], 'C' => [['D', 1.7]], 'D' => []}
  start = 'A'
  end_node = 'D'
  result = dijkstra(graph, start, end_node)
  puts result
end

main()