def transform_coordinates(x, y, z, a, b, c)
  x_new = x * a
  y_new = y * b
  z_new = z * c
  return [x_new, y_new, z_new]
end

if __FILE__ == $0
  x, y, z = [1, 2, 3]
  a, b, c = [2, 3, 4]
  result = transform_coordinates(x, y, z, a, b, c)
  puts result.inspect
end