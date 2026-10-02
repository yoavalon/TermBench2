require 'matrix'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  radians_x = angle_x * Math::PI / 180
  radians_y = angle_y * Math::PI / 180
  radians_z = angle_z * Math::PI / 180
  rotation_x = Matrix[
    [1, 0, 0],
    [0, Math.cos(radians_x), -Math.sin(radians_x)],
    [0, Math.sin(radians_x), Math.cos(radians_x)]
  ]
  rotation_y = Matrix[
    [Math.cos(radians_y), 0, Math.sin(radians_y)],
    [0, 1, 0],
    [-Math.sin(radians_y), 0, Math.cos(radians_y)]
  ]
  rotation_z = Matrix[
    [Math.cos(radians_z), -Math.sin(radians_z), 0],
    [Math.sin(radians_z), Math.cos(radians_z), 0],
    [0, 0, 1]
  ]
  point = Matrix.column_vector([x, y, z])
  transformed_point = rotation_x * rotation_y * rotation_z * point
  transformed_point.to_a.flatten
end

def continuously_transform
  x, y, z = (1.0, 0.0, 0.0)
  angle_x, angle_y, angle_z = (10.0, 20.0, 30.0)
  loop do
    x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    angle_x, angle_y, angle_z = ((angle_x + 5) % 360.0, (angle_y + 10) % 360.0, (angle_z + 15) % 360.0)
  end
end

def main
  continuously_transform
end

main