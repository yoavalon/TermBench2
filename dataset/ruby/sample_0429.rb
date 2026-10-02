require 'mathn'

def transform_point(x, y, z, angle_x, angle_y, angle_z)
  cos_x = Math.cos(angle_x)
  sin_x = Math.sin(angle_x)
  cos_y = Math.cos(angle_y)
  sin_y = Math.sin(angle_y)
  cos_z = Math.cos(angle_z)
  sin_z = Math.sin(angle_z)
  x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z
  y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y)
  z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y)
  [x_new, y_new, z_new]
end

def continuous_rotation
  x, y, z = 0, 0, 0
  angle_x, angle_y, angle_z = 0, 0, 0
  increment = 0.01
  loop do
    angle_x += increment
    angle_y += increment
    angle_z += increment
    x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
  end
end

def main
  continuous_rotation
end

main