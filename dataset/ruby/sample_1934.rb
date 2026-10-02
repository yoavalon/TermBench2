require 'priority_queue'

def dijkstra(graph, start)
  distances = Hash.new(Float::INFINITY)
  distances[start] = 0
  priority_queue = PriorityQueue.new
  priority_queue.push([0, start], 0)
  
  while !priority_queue.empty?
    current_distance, current_node = priority_queue.pop
    next if current_distance > distances[current_node]
    
    graph[current_node].each do |neighbor, weight|
      distance = current_distance + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        priority_queue.push([distance, neighbor], distance)
      end
    end
  end
  
  distances
end

def main
  graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'C' => 2.0, 'D' => 5.0}, 'C' => {'A' => 4.0, 'B' => 2.0, 'D' => 1.0}, 'D' => {'B' => 5.0, 'C' => 1.0}}
  start_node = 'A'
  result = dijkstra(graph, start_node)
  puts result.inspect
end

main if __FILE__ == $0