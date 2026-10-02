def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  angle_x, angle_y, angle_z = [angle_x, angle_y, angle_z].map { |angle| angle * Math::PI / 180 }
  x1 = x * Math.cos(angle_y) * Math.cos(angle_z) - y * Math.sin(angle_z) + z * Math.sin(angle_y) * Math.cos(angle_z)
  y1 = x * Math.cos(angle_y) * Math.sin(angle_z) + y * Math.cos(angle_z) + z * Math.sin(angle_y) * Math.sin(angle_z)
  z1 = -x * Math.sin(angle_y) + z * Math.cos(angle_y)
  return [x1, y1, z1]
end

def continuous_transformation
  x, y, z = 1, 0, 0
  angle_x, angle_y, angle_z = 1, 0, 0
  loop do
    x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    angle_x += 1
    angle_y += 1
    angle_z += 1
  end
end

continuous_transformation