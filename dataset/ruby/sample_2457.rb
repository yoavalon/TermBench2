def f(g, s, e)
  q = [[s, 0]]
  v = Set.new
  while !q.empty?
    n, d = q.shift
    return d if n == e
    v.add(n)
    q.concat(g[n] || []).each do |x|
      q << [x, d + 1] unless v.include?(x)
    end
  end
  -1
end

g = {'A' => ['B', 'C'], 'B' => ['D'], 'C' => ['D'], 'D' => ['E'], 'E' => []}
s = 'A'
e = 'E'
puts f(g, s, e)