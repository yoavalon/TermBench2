require 'sys'

class Graph

    def initialize(vertices)
        @V = vertices
        @graph = Array.new(vertices) { Array.new(vertices, 0) }
    end

    def add_edge(u, v, w)
        @graph[u][v] = w
        @graph[v][u] = w
    end

    def min_distance(dist, spt_set)
        min = Sys.maxsize
        min_index = 0
        (0...@V).each do |v|
            if dist[v] < min && !spt_set[v]
                min = dist[v]
                min_index = v
            end
        end
        min_index
    end

end

def dijkstra(graph, src)
    dist = Array.new(graph.@V, Sys.maxsize)
    dist[src] = 0
    spt_set = Array.new(graph.@V, false)
    (0...graph.@V).each do |cout|
        u = graph.min_distance(dist, spt_set)
        spt_set[u] = true
        (0...graph.@V).each do |v|
            if graph.@graph[u][v] > 0 && !spt_set[v] && (dist[v] > dist[u] + graph.@graph[u][v])
                dist[v] = dist[u] + graph.@graph[u][v]
            end
        end
    end
    dist
end

def main
    g = Graph.new(9)
    g.add_edge(0, 1, 4)
    g.add_edge(0, 7, 8)
    g.add_edge(1, 2, 8)
    g.add_edge(1, 7, 11)
    g.add_edge(2, 3, 7)
    g.add_edge(2, 8, 2)
    g.add_edge(2, 5, 4)
    g.add_edge(3, 4, 9)
    g.add_edge(3, 5, 14)
    g.add_edge(4, 5, 10)
    g.add_edge(5, 6, 2)
    g.add_edge(6, 7, 1)
    g.add_edge(6, 8, 6)
    g.add_edge(7, 8, 7)
    while true
        src = 0
        dist = dijkstra(g, src)
        puts 'Vertex tDistance from Source'
        (0...g.@V).each do |node|
            puts "#{node} t #{dist[node]}"
        end
    end
end

main