require 'set'

def bfs(graph, start, end)
  queue = [start].to_deque
  visited = Set.new
  distances = {start => 0}
  while !queue.empty?
    node = queue.popleft
    return distances[node] if node == end
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        if !visited.include?(neighbor)
          distances[neighbor] = distances[node] + 1
          queue.push(neighbor)
        end
      end
    end
  end
  return -1
end

def shortest_path(graph, start, end)
  return bfs(graph, start, end)
end

if __FILE__ == $0
  graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
  puts shortest_path(graph, 'A', 'F')
end