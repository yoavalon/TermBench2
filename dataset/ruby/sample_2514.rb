require 'queue'

def bfs_shortest_path(graph, start, goal)
  queue = Queue.new
  queue << [start, [start]]
  visited = Set.new
  while !queue.empty?
    node, path = queue.pop
    return path if node == goal
    if !visited.include?(node)
      visited.add(node)
      graph[node].each do |neighbor|
        queue << [neighbor, path + [neighbor]] if !visited.include?(neighbor)
      end
    end
  end
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['F'], 'F' => ['G'], 'G' => []}
  start_node = 'A'
  goal_node = 'G'
  result = bfs_shortest_path(graph, start_node, goal_node)
  puts result
end

main