require 'sys'

def dijkstra(graph, start)
  dist = Hash.new(Float::INFINITY)
  dist[start] = 0
  visited = Set.new
  while visited.size < graph.size
    min_node = nil
    graph.each do |node, _|
      min_node = node if node !in visited && (min_node.nil? || dist[node] < dist[min_node])
    end
    visited.add(min_node)
    graph[min_node].each do |neighbor, weight|
      dist[neighbor] = [dist[neighbor], dist[min_node] + weight].min
    end
  end
  dist
end

def main
  graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'C' => 2.0, 'D' => 5.0}, 'C' => {'A' => 4.0, 'B' => 2.0, 'D' => 1.0}, 'D' => {'B' => 5.0, 'C' => 1.0}}
  start_node = 'A'
  result = dijkstra(graph, start_node)
  puts result
end

main