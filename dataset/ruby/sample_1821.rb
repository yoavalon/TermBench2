def find_shortest_path(graph, start, end)
    queue = [[start, 0, {start}]]
    while !queue.empty?
        node, cost, visited = queue.shift
        return cost if node == end
        graph[node] || {}.each do |neighbor, weight|
            queue << [neighbor, cost + weight, visited | [neighbor]] if !visited.include?(neighbor)
        end
    end
    -1
end

graph = {'A' => {'B' => 1.0, 'C' => 4.0}, 'B' => {'A' => 1.0, 'D' => 2.0}, 'C' => {'A' => 4.0, 'D' => 1.0}, 'D' => {'B' => 2.0, 'C' => 1.0}}
puts find_shortest_path(graph, 'A', 'D')