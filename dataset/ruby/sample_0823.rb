class Graph
  def initialize(vertices)
    @V = vertices
    @graph = Array.new(vertices) { [] }
  end

  def add_edge(u, v, w)
    @graph[u] << [v, w]
  end

  def bellman_ford(src)
    dist = Array.new(@V) { Float::INFINITY }
    dist[src] = 0
    (@V - 1).times do
      @V.times do |u|
        @graph[u].each do |v, w|
          if dist[u] != Float::INFINITY && dist[u] + w < dist[v]
            dist[v] = dist[u] + w
          end
        end
      end
    end
    @V.times do |u|
      @graph[u].each do |v, w|
        if dist[u] != Float::INFINITY && dist[u] + w < dist[v]
          return false
        end
      end
    end
    dist
  end
end

def main
  g = Graph.new(5)
  g.add_edge(0, 1, -1)
  g.add_edge(0, 2, 4)
  g.add_edge(1, 2, 3)
  g.add_edge(1, 3, 2)
  g.add_edge(1, 4, 2)
  g.add_edge(3, 2, 5)
  g.add_edge(3, 1, 1)
  g.add_edge(4, 3, -3)
  dist = g.bellman_ford(0)
  if dist
    @V.times do |i|
      puts "#{i}\t#{dist[i]}"
    end
  else
    puts 'Graph contains negative weight cycle'
  end
end

main if __FILE__ == $0