require 'set'

def bfs(graph, start, end)
  queue = [[start, [start]]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.shift
    if node == end
      return path
    end
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue.push([neighbor, path + [neighbor]])
      end
    end
  end
  nil
end

def find_shortest_path(graph, start, end)
  path = bfs(graph, start, end)
  if path
    path.length - 1
  else
    -1
  end
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
  start = 'A'
  end_node = 'F'
  puts find_shortest_path(graph, start, end_node)
end

main