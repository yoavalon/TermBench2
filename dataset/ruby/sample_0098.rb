def transform_3d_coordinates(x, y, z, a, b, c)
  x_new = a * x + b * y + c * z
  y_new = b * x + a * y - c * z
  z_new = c * x - b * y + a * z
  return [x_new, y_new, z_new]
end

def main
  x, y, z = 1, 2, 3
  a, b, c = 0, 1, 0
  x_new, y_new, z_new = transform_3d_coordinates(x, y, z, a, b, c)
  puts "#{x_new} #{y_new} #{z_new}"
end

main