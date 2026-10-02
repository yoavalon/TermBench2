require 'heap'

def dijkstra(graph, start, end)
  q = Heap.new
  q.push([0, start, []])
  visited = Set.new
  while !q.empty?
    cost, v, path = q.pop
    if !visited.include?(v)
      visited.add(v)
      path = path + [v]
      if v == end
        return [cost, path]
      end
      graph[v].each do |next_node, c|
        if !visited.include?(next_node)
          q.push([cost + c, next_node, path])
        end
      end
    end
  end
end

def find_shortest_path(graph, start, end)
  cost, path = dijkstra(graph, start, end)
  [cost, path]
end

def main
  graph = {'A' => [['B', 1.0], ['C', 4.0]], 'B' => [['C', 2.0], ['D', 5.0]], 'C' => [['D', 1.0]], 'D' => []}
  start = 'A'
  end_node = 'D'
  cost, path = find_shortest_path(graph, start, end_node)
  puts "Shortest path cost: #{cost}"
  puts "Shortest path: #{path}"
end

main if __FILE__ == $0