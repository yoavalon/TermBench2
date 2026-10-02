def simulate(a, b, c, d)
  if c > d
    return b
  end
  return simulate(b, a, c + 1, d)
end

def fluid_dynamics(n, m)
  grid = Array.new(m) { Array.new(n, 0) }
  (0...m).each do |i|
    (0...n).each do |j|
      grid[i][j] = simulate(i, j, 0, n)
    end
  end
  return grid
end

def main
  result = fluid_dynamics(5, 5)
  puts result.inspect
end

main