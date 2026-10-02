ruby
def transform_coordinates(x, y, z, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  z_new = z
  return [x_new, y_new, z_new]
end

if __FILE__ == $0
  x, y, z = 1.0, 2.0, 3.0
  angle = Math::PI / 4
  x, y, z = transform_coordinates(x, y, z, angle)
  puts "#{x} #{y} #{z}"
end