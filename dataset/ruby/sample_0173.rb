require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  angle_x_rad = angle_x * Math::PI / 180
  angle_y_rad = angle_y * Math::PI / 180
  angle_z_rad = angle_z * Math::PI / 180
  cos_x = Math.cos(angle_x_rad)
  sin_x = Math.sin(angle_x_rad)
  cos_y = Math.cos(angle_y_rad)
  sin_y = Math.sin(angle_y_rad)
  cos_z = Math.cos(angle_z_rad)
  sin_z = Math.sin(angle_z_rad)
  x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
  y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
  z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  return [x_new, y_new, z_new]
end

def apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z)
  x = [min_x, [x, max_x].min].max
  y = [min_y, [y, max_y].min].max
  z = [min_z, [z, max_z].min].max
  return [x, y, z]
end

def main
  x, y, z = 5, 10, 15
  angle_x, angle_y, angle_z = 30, 45, 60
  min_x, max_x, min_y, max_y, min_z, max_z = -100, 100, -100, 100, -100, 100
  x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  x, y, z = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z)
  puts "Transformed and bounded coordinates: (#{x}, #{y}, #{z})"
end

main