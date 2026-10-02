require 'priority_queue'

def dijkstra(graph, start, end)
  queue = PriorityQueue.new
  queue.push([0, start])
  visited = Set.new
  while !queue.empty?
    cost, node = queue.pop
    return cost if node == end
    next if visited.include?(node)
    visited.add(node)
    (graph[node] || []).each do |neighbor, weight|
      queue.push([cost + weight, neighbor])
    end
  end
  Float::INFINITY
end

def shortest_path(graph, start, end)
  dijkstra(graph, start, end)
end

def main
  graph = {'A' => [['B', 1], ['C', 4]], 'B' => [['A', 1], ['C', 2], ['D', 5]], 'C' => [['A', 4], ['B', 2], ['D', 1]], 'D' => [['B', 5], ['C', 1]]}
  start = 'A'
  end_node = 'D'
  puts shortest_path(graph, start, end_node)
end

main