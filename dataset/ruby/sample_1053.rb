ruby
def find_path(graph, start, end, path=[])
  path = path + [start]
  if start == end
    return path
  end
  if !graph.key?(start)
    return nil
  end
  graph[start].each do |node|
    if !path.include?(node)
      newpath = find_path(graph, node, end, path)
      if newpath
        return newpath
      end
    end
  end
  return nil
end

def non_terminating_search(graph, start, end)
  loop do
    result = find_path(graph, start, end)
    if result
      puts result.inspect
    else
      puts 'No path found'
    end
  end
end

graph = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
non_terminating_search(graph, 'A', 'F')