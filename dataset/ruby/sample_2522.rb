def bfs(graph, start, goal)
  queue = [[start, [start]]]
  while !queue.empty?
    vertex, path = queue.shift
    (graph[vertex] - path).each do |next_vertex|
      if next_vertex == goal
        return path + [next_vertex]
      else
        queue.push([next_vertex, path + [next_vertex]])
      end
    end
  end
  return nil
end

def find_path(graph, start, goal)
  path = bfs(graph, start, goal)
  path ? path : []
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
  start_node = 'A'
  goal_node = 'F'
  result = find_path(graph, start_node, goal_node)
  puts result
end

main