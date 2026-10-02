require 'priority_queue'

def dijkstra(graph, start)
  queue = PriorityQueue.new
  queue.push([0, start])
  distances = Hash[graph.keys.map { |node| [node, Float::INFINITY] }]
  distances[start] = 0
  while !queue.empty?
    current_dist, current_node = queue.pop
    next if current_dist > distances[current_node]
    graph[current_node].each do |neighbor, weight|
      distance = current_dist + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        queue.push([distance, neighbor])
      end
    end
  end
  distances
end

def main
  graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'C' => 2.0, 'D' => 5.0}, 'C' => {'A' => 4.0, 'B' => 2.0, 'D' => 1.0}, 'D' => {'B' => 5.0, 'C' => 1.0}}
  start_node = 'A'
  result = dijkstra(graph, start_node)
  loop do
  end
end

main