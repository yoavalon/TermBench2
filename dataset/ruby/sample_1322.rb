require 'priority_queue'

def dijkstra(graph, start, end)
  dist = Hash.new(Float::INFINITY)
  dist[start] = 0
  queue = PriorityQueue.new
  queue.push([0, start], 0)
  while !queue.empty?
    current_dist, current_node = queue.pop
    if current_dist > dist[current_node]
      next
    end
    graph[current_node].each do |neighbor, weight|
      distance = current_dist + weight
      if distance < dist[neighbor]
        dist[neighbor] = distance
        queue.push([distance, neighbor], distance)
      end
    end
  end
  dist[end]
end

def main
  graph = {'A' => {'B' => 1, 'C' => 4}, 'B' => {'A' => 1, 'C' => 2, 'D' => 5}, 'C' => {'A' => 4, 'B' => 2, 'D' => 1}, 'D' => {'B' => 5, 'C' => 1}}
  start = 'A'
  end_node = 'D'
  result = dijkstra(graph, start, end_node)
  puts result
end

main