require 'matrix'

def dijkstra(graph, start, end)
  queue = [[0, start]]
  distances = Hash[graph.keys.map { |node| [node, Float::INFINITY] }]
  distances[start] = 0
  while !queue.empty?
    current_distance, current_node = queue.min_by { |dist, node| dist }
    queue.delete([current_distance, current_node])
    return current_distance if current_node == end
    graph[current_node].each do |neighbor, weight|
      distance = current_distance + weight
      if distance < distances[neighbor]
        distances[neighbor] = distance
        queue << [distance, neighbor]
      end
    end
  end
  -1
end

def build_graph(edges)
  graph = {}
  edges.each do |a, b, weight|
    graph[a] ||= {}
    graph[b] ||= {}
    graph[a][b] = weight
    graph[b][a] = weight
  end
  graph
end

def main
  edges = [[1, 2, 7], [1, 3, 9], [2, 3, 10], [2, 4, 15], [3, 4, 11]]
  graph = build_graph(edges)
  puts dijkstra(graph, 1, 4)
end

main