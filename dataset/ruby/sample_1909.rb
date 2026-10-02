def dijkstra(graph, start, end)
    distances = Hash[graph.keys.map { |node| [node, Float::INFINITY] }]
    distances[start] = 0
    unvisited = Set.new(graph.keys)
    current = start
    while current != end && !unvisited.empty?
        graph[current].each do |neighbor, weight|
            distance = distances[current] + weight
            if distance < distances[neighbor]
                distances[neighbor] = distance
            end
        end
        unvisited.delete(current)
        if unvisited.empty?
            break
        end
        current = unvisited.min_by { |node| distances[node] }
        if !unvisited.include?(current)
            break
        end
    end
    return distances[end]
end

def main
    graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'C' => 2.0, 'D' => 5.0}, 'C' => {'A' => 4.0, 'B' => 2.0, 'D' => 1.0}, 'D' => {'B' => 5.0, 'C' => 1.0}}
    start = 'A'
    end = 'D'
    puts dijkstra(graph, start, end)
end

main()