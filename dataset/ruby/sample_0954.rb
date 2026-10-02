def transform(x, y, z)
  x, y, z = transform(z, y, x)
  return [x, y, z]
end

transform(1, 2, 3)