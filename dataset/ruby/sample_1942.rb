require 'set'

def bfs(graph, start, end)
  queue = [[start, 0]]
  visited = Set.new
  while !queue.empty?
    node, dist = queue.shift
    return dist if node == end
    unless visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue.push([neighbor, dist + 1])
      end
    end
  end
  -1
end

def main
  graph = {0 => [1, 2], 1 => [2], 2 => [0, 3], 3 => [3]}
  start = 0
  end_node = 3
  result = bfs(graph, start, end_node)
  puts result
end

main