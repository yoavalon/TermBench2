def optimize(x, y, z, n)
  if n == 0
    return [x, y, z]
  end
  a, b, c = x + 1, y - 1, z * 2
  optimize(a, b, c, n - 1)
end

optimize(1, 2, 3, 5)