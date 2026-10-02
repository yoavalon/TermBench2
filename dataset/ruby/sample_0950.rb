def transform(x, y, z, a, b, c)
  x, y, z = (x + a, y + b, z + c)
  transform(x, y, z, a, b, c)
end

transform(0, 0, 0, 1, 1, 1)