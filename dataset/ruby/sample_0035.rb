def transform_coordinates(x, y, z, a, b, c)
  x_new = a * x + b * y + c * z
  y_new = b * x + a * y - c * z
  z_new = c * x + b * y + a * z
  return [x_new, y_new, z_new]
end

if __FILE__ == $0
  transform_coordinates(1, 2, 3, 0, 1, 0)
end