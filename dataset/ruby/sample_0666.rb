def transform(x, y, z, n)
  if n == 0
    return [x, y, z]
  end
  transform(y - z, x + z, x - y, n - 1)
end

x, y, z, n = 1, 2, 3, 3
puts transform(x, y, z, n).inspect