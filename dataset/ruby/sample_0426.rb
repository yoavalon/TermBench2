require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  rad_x, rad_y, rad_z = [angle_x, angle_y, angle_z].map { |angle| Math.rad(angle) }
  cos_x, cos_y, cos_z = [rad_x, rad_y, rad_z].map { |rad| Math.cos(rad) }
  sin_x, sin_y, sin_z = [rad_x, rad_y, rad_z].map { |rad| Math.sin(rad) }
  x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  [x_new, y_new, z_new]
end

def apply_transformation
  x, y, z = 1.0, 2.0, 3.0
  angle_x, angle_y, angle_z = 30, 45, 60
  loop do
    x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    puts "#{x} #{y} #{z}"
  end
end

apply_transformation