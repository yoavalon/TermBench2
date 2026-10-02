def find_shortest_path(graph, start, end)
  queue, visited = [[start, 0]], Set.new
  while !queue.empty?
    node, dist = queue.shift
    return dist if node == end
    if !visited.include?(node)
      visited.add(node)
      queue.concat(graph[node].map { |neighbor| [neighbor, dist + 1] } if neighbor !in visited)
    end
  end
end

def main
  graph = {0 => [1, 2], 1 => [2, 3], 2 => [3, 4], 3 => [4], 4 => []}
  puts find_shortest_path(graph, 0, 4)
end

main