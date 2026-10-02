def find_path(graph, start, end, path = nil)
  path ||= []
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

def shortest_path(graph, start, end)
  path = find_path(graph, start, end)
  return path ? path.length - 1 : Float::INFINITY
end

g = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => [], 'E' => ['F'], 'F' => []}
puts shortest_path(g, 'A', 'F')