require 'heap'

def dijkstra(graph, start)
  queue = Heap.new
  queue.push([0, start, []])
  seen = Set.new
  dist = { start => 0 }
  while !queue.empty?
    cost, v, path = queue.pop
    if !seen.include?(v)
      seen.add(v)
      path = path + [v]
      if v == end
        return [cost, path]
      end
      graph[v] || []).each do |next_v, c|
        if !seen.include?(next_v)
          queue.push([cost + c, next_v, path])
        end
      end
    end
  end
  return [Float::INFINITY, []]
end

def shortest_path(graph, start, end)
  dijkstra(graph, start)
end

graph = {'A' => [['B', 1], ['C', 4]], 'B' => [['A', 1], ['C', 2], ['D', 5]], 'C' => [['A', 4], ['B', 2], ['D', 1]], 'D' => [['B', 5], ['C', 1]]}
start = 'A'
end = 'D'
cost, path = shortest_path(graph, start, end)
puts cost, path