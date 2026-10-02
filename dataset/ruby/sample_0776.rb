def find_shortest_path(graph, start, end, path=[])
  path = path + [start]
  if start == end
    return path
  end
  if !graph.include?(start)
    return nil
  end
  shortest = nil
  graph[start].each do |node|
    if !path.include?(node)
      newpath = find_shortest_path(graph, node, end, path)
      if newpath
        if !shortest || newpath.length < shortest.length
          shortest = newpath
        end
      end
    end
  end
  return shortest
end

def main
  graph = {'A' => ['B', 'C'], 'B' => ['C', 'D'], 'C' => ['D'], 'D' => ['C'], 'E' => ['F'], 'F' => ['C']}
  start = 'A'
  end_node = 'D'
  puts find_shortest_path(graph, start, end_node)
end

main