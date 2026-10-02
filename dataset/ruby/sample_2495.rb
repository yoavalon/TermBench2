def find_shortest_path(graph, start, end)
  q, v = [[start, 0]], []
  while !q.empty?
    n, d = q.shift
    return d if n == end
    v << n
    graph.fetch(n, []).each do |nxt|
      q << [nxt, d + 1] unless v.include?(nxt)
    end
  end
  -1
end

g = {'A' => ['B', 'C'], 'B' => ['D', 'E'], 'C' => ['F'], 'D' => ['G'], 'E' => ['F'], 'F' => ['G'], 'G' => []}
result = find_shortest_path(g, 'A', 'G')
puts result