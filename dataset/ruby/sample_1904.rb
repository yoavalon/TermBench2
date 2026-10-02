def init_matrix(size)
  Array.new(size) { Array.new(size, Float::INFINITY) }
end

def update_distance(graph, dist, src, size)
  (0...size).each do |v|
    if graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]
      dist[v] = dist[src] + graph[src][v]
    end
  end
end

def shortest_path(graph, src, size)
  dist = Array.new(size, Float::INFINITY)
  dist[src] = 0
  (size - 1).times do
    update_distance(graph, dist, src, size)
  end
  dist
end

def main
  graph = [[0, 5, Float::INFINITY, 10], [Float::INFINITY, 0, 3, Float::INFINITY], [Float::INFINITY, Float::INFINITY, 0, 1], [Float::INFINITY, Float::INFINITY, Float::INFINITY, 0]]
  size = graph.length
  result = shortest_path(graph, 0, size)
  puts result.inspect
end

main