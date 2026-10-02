require 'mathn'

def transform_point(x, y, z, angle_x, angle_y, angle_z)
  cos_x, sin_x = [Math.cos(angle_x), Math.sin(angle_x)]
  cos_y, sin_y = [Math.cos(angle_y), Math.sin(angle_y)]
  cos_z, sin_z = [Math.cos(angle_z), Math.sin(angle_z)]
  x_new = x * cos_y * cos_z + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z)
  y_new = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (sin_x * cos_z - cos_x * sin_y * sin_z)
  z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  [x_new, y_new, z_new]
end

def main
  x, y, z = 1.0, 2.0, 3.0
  angle_x, angle_y, angle_z = [Math::PI / 4, Math::PI / 3, Math::PI / 6]
  loop do
    x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
    puts "Transformed Point: (#{x}, #{y}, #{z})"
  end
end

main