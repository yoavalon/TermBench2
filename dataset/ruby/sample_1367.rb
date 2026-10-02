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
        return [path, cost]
      end
      graph[node] ||= {}
      graph[node].each do |neighbor, c|
        if !visited.include?(neighbor)
          queue.push([cost + c, neighbor, path])
        end
      end
    end
  end
end

def main
  graph = {'A' => {'B' => 1, 'C' => 4}, 'B' => {'A' => 1, 'C' => 2, 'D' => 5}, 'C' => {'A' => 4, 'B' => 2, 'D' => 1}, 'D' => {'B' => 5, 'C' => 1}}
  start_node = 'A'
  end_node = 'D'
  path, cost = dijkstra(graph, start_node, end_node)
  puts "Path: #{path}, Cost: #{cost}"
end

main