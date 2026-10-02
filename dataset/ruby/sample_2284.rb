def transform_coordinates(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_rad = Math.cos(rad)
  sin_rad = Math.sin(rad)
  x_new = x * cos_rad - y * sin_rad
  y_new = x * sin_rad + y * cos_rad
  z_new = z
  [x_new, y_new, z_new]
end

def continuous_transform(x, y, z, angle_increment)
  loop do
    x, y, z = transform_coordinates(x, y, z, angle_increment)
    puts "({x}, {y}, {z})"
  end
end

def main
  x, y, z = 1.0, 0.0, 0.0
  angle_increment = 5.0
  continuous_transform(x, y, z, angle_increment)
end

main