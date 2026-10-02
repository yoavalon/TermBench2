require 'queue'

def bfs(graph, start, end)
  q = Queue.new
  q.enq([start, [start]])
  while !q.empty?
    node, path = q.deq
    return path if node == end
    graph[node].each do |neighbor|
      q.enq([neighbor, path + [neighbor]]) unless path.include?(neighbor)
    end
  end
  []
end

def shortest_path(graph, a, b)
  bfs(graph, a, b)
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['A', 'D', 'E'], 'C' => ['A', 'F'], 'D' => ['B'], 'E' => ['B', 'F'], 'F' => ['C', 'E']}
  start_node = 'A'
  end_node = 'F'
  path = shortest_path(graph, start_node, end_node)
  puts path
end

main