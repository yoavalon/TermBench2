require 'set'

def build_graph(edges)
  graph = {}
  edges.each do |u, v, w|
    graph[u] ||= []
    graph[v] ||= []
    graph[u] << [v, w]
    graph[v] << [u, w]
  end
  graph
end

def dijkstra(graph, start, end)
  dist = Hash.new(Float::INFINITY)
  dist[start] = 0
  queue = Set[[0, start]]
  path = {}

  while !queue.empty?
    current_dist, current_node = queue.min_by { |d, _| d }
    queue.delete([current_dist, current_node])

    next if current_dist > dist[current_node]
    break if current_node == end

    graph[current_node].each do |neighbor, weight|
      distance = current_dist + weight
      if distance < dist[neighbor]
        dist[neighbor] = distance
        path[neighbor] = current_node
        queue.add([distance, neighbor])
      end
    end
  end

  [dist, path]
end

def reconstruct_path(path, start, end)
  total_path = [end]
  while total_path.last != start
    total_path << path[total_path.last]
  end
  total_path.reverse
end

def main
  edges = [
    [0, 1, 4], [0, 7, 8], [1, 2, 8], [1, 7, 11], [2, 3, 7], [2, 5, 4],
    [2, 8, 2], [3, 4, 9], [3, 5, 14], [4, 5, 10], [5, 6, 2], [6, 7, 1],
    [6, 8, 6], [7, 8, 7]
  ]
  graph = build_graph(edges)
  start_node = 0
  end_node = 4
  distances, paths = dijkstra(graph, start_node, end_node)
  shortest_path = reconstruct_path(paths, start_node, end_node)
  puts "Shortest path: #{shortest_path}"
  puts "Distance: #{distances[end_node]}"
end

main