def find_shortest_path(graph, start, end)
    queue = [[start, 0]]
    visited = Set.new
    while !queue.empty?
        node, dist = queue.shift
        if node == end
            return dist
        end
        if visited.include?(node)
            next
        end
        visited.add(node)
        graph[node].each do |neighbor, weight|
            queue.push([neighbor, dist + weight])
        end
    end
    return -1
end

def main
    graph = {'A'=>[['B', 1.1], ['C', 4.5]], 'B'=>[['A', 1.1], ['C', 2.3], ['D', 5.6]], 'C'=>[['A', 4.5], ['B', 2.3], ['D', 1.2]], 'D'=>[['B', 5.6], ['C', 1.2]]}
    result = find_shortest_path(graph, 'A', 'D')
    puts result
end

main()