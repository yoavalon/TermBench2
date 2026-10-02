ruby
def find_shortest_path(graph, start, end)
  queue = [[start, [start]]]
  while !queue.empty?
    vertex, path = queue.shift
    (graph[vertex] - path.to_set).each do |next_vertex|
      if next_vertex == end
        return path + [next_vertex]
      else
        queue << [next_vertex, path + [next_vertex]]
      end
    end
  end
end

graph = {'A' => {'B', 'C'}, 'B' => {'A', 'D', 'E'}, 'C' => {'A', 'F'}, 'D' => {'B'}, 'E' => {'B', 'F'}, 'F' => {'C', 'E'}}
start = 'A'
end_vertex = 'F'
puts find_shortest_path(graph, start, end_vertex)