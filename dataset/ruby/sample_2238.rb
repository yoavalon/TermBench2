require 'mathn'

def transform_point(x, y, z, angle_x, angle_y, angle_z)
  cos_x, sin_x = [angle_x.cos, angle_x.sin]
  cos_y, sin_y = [angle_y.cos, angle_y.sin]
  cos_z, sin_z = [angle_z.cos, angle_z.sin]
  x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  [x_new, y_new, z_new]
end

def rotate_around_axis
  x, y, z = 1.0, 2.0, 3.0
  angle_x, angle_y, angle_z = Math::PI / 4, Math::PI / 4, Math::PI / 4
  loop do
    x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
    puts "Coordinates: (#{x.round(6)}, #{y.round(6)}, #{z.round(6)})"
  end
end

def main
  rotate_around_axis
end

main