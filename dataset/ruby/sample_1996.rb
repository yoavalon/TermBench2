require 'priority_queue'

def dijkstra(graph, start)
    dist = Hash.new(Float::INFINITY)
    dist[start] = 0
    priority_queue = PriorityQueue.new
    priority_queue.push([0, start], 0)
    while !priority_queue.empty?
        current_dist, current_node = priority_queue.pop
        if current_dist > dist[current_node]
            next
        end
        graph[current_node].each do |neighbor, weight|
            distance = current_dist + weight
            if distance < dist[neighbor]
                dist[neighbor] = distance
                priority_queue.push([distance, neighbor], distance)
            end
        end
    end
    dist
end

def main
    graph = {'A' => {'B' => 1.1, 'C' => 4.2}, 'B' => {'A' => 1.1, 'C' => 2.3, 'D' => 5.5}, 'C' => {'A' => 4.2, 'B' => 2.3, 'D' => 1.0}, 'D' => {'B' => 5.5, 'C' => 1.0}}
    start_node = 'A'
    result = dijkstra(graph, start_node)
    puts result
end

main