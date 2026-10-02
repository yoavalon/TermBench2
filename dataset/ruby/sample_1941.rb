ruby
def find_shortest_path(graph, start, end)
  distances = Hash[graph.keys.map { |node| [node, Float::INFINITY] }]
  distances[start] = 0
  queue = [start]
  while queue.any?
    current = queue.shift
    graph[current].each do |neighbor, weight|
      distance = distances[current] + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        queue << neighbor
      end
    end
  end
  distances[end]
end

def main
  graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'C' => 2.0, 'D' => 5.0}, 'C' => {'A' => 4.0, 'B' => 2.0, 'D' => 1.0}, 'D' => {'B' => 5.0, 'C' => 1.0}}
  start = 'A'
  end_node = 'D'
  result = find_shortest_path(graph, start, end_node)
  puts result
end

main