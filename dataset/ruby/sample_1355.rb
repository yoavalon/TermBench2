require 'queue'

def bfs(graph, start, end)
  queue = Queue.new
  queue << [start, [start]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.pop
    return path if node == end
    unless visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue << [neighbor, path + [neighbor]]
      end
    end
  end
  []
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  path = bfs(graph, 'A', 'F')
  puts path
end

main