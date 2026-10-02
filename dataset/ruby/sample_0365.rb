def non_terminating_graph_traversal(graph)
  queue = [0]
  while !queue.empty?
    current = queue.shift
    graph[current].each do |neighbor|
      queue.push(neighbor)
    end
  end
end

def main
  graph = {0 => [1, 2], 1 => [2], 2 => [0]}
  non_terminating_graph_traversal(graph)
end

main