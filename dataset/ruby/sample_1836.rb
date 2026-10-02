def transform_coordinates(x, y, z, a, b, c)
  x1 = x * a + y * b + z * c
  y1 = x * b - y * a + z * c
  z1 = x * c + y * c - z * a
  return [x1, y1, z1]
end

if __FILE__ == $0
  transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5)
end