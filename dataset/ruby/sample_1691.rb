def bfs(graph, start, end)
  queue = [[start, [start]]]
  while !queue.empty?
    node, path = queue.shift
    graph[node].each do |neighbor|
      unless path.include?(neighbor)
        if neighbor == end
          return path + [neighbor]
        end
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
end

def process_graph
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start = 'A'
  end_node = 'F'
  while true
    path = bfs(graph, start, end_node)
    if path
      puts "Path found: #{path}"
    end
  end
end

process_graph