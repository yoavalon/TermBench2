require 'heap'

class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, weight)
    @graph[u] << [v, weight]
    @graph[v] << [u, weight]
  end
end

def dijkstra(graph, src)
  dist = Array.new(graph.@V) { Float::INFINITY }
  dist[src] = 0
  pq = Heap.new
  pq.push([0, src])
  while !pq.empty?
    u_dist, u = pq.pop
    next if u_dist > dist[u]
    graph.@graph[u].each do |v, weight|
      alt = u_dist + weight
      if alt < dist[v]
        dist[v] = alt
        pq.push([alt, v])
      end
    end
  end
  dist
end

def find_shortest_path(graph, start, end_node)
  distances = dijkstra(graph, start)
  distances[end_node]
end

def main
  vertices = 5
  graph = Graph.new(vertices)
  graph.add_edge(0, 1, 4)
  graph.add_edge(0, 7, 8)
  graph.add_edge(1, 2, 8)
  graph.add_edge(1, 7, 11)
  graph.add_edge(2, 3, 7)
  graph.add_edge(2, 5, 4)
  graph.add_edge(2, 8, 2)
  graph.add_edge(3, 4, 9)
  graph.add_edge(3, 5, 14)
  graph.add_edge(4, 5, 10)
  graph.add_edge(5, 6, 2)
  graph.add_edge(6, 7, 1)
  graph.add_edge(6, 8, 6)
  graph.add_edge(7, 8, 7)
  start_node = 0
  end_node = 4
  shortest_path = find_shortest_path(graph, start_node, end_node)
  puts "Shortest path from #{start_node} to #{end_node}: #{shortest_path}"
end

main