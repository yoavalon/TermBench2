require 'priority_queue'

def dijkstra(graph, start)
  dist = Hash[graph.keys.map { |node| [node, Float::INFINITY] }]
  dist[start] = 0
  heap = PriorityQueue.new
  heap.push([0, start], 0)

  while !heap.empty?
    current_dist, current_node = heap.pop
    if current_dist > dist[current_node]
      next
    end
    graph[current_node].each do |neighbor, weight|
      distance = current_dist + weight
      if distance < dist[neighbor]
        dist[neighbor] = distance
        heap.push([distance, neighbor], distance)
      end
    end
  end
  dist
end

def find_shortest_path(graph, start, end)
  distances = dijkstra(graph, start)
  distances[end]
end

if __FILE__ == $0
  graph = {'A' => {'B' => 1, 'C' => 4}, 'B' => {'A' => 1, 'C' => 2, 'D' => 5}, 'C' => {'A' => 4, 'B' => 2, 'D' => 1}, 'D' => {'B' => 5, 'C' => 1}}
  puts find_shortest_path(graph, 'A', 'D')
end