require 'set'

def bfs(graph, start, end)
  queue = Queue.new
  queue.push([start, [start]])
  visited = Set.new
  while !queue.empty?
    node, path = queue.pop
    return path if node == end
    visited.add(node)
    (graph[node] - visited).each do |neighbor|
      queue.push([neighbor, path + [neighbor]])
    end
  end
  nil
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
  start_node = 'A'
  end_node = 'F'
  result = bfs(graph, start_node, end_node)
  if result
    puts result
  else
    puts 'No path found'
  end
end

main()