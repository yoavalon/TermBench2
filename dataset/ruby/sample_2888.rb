require 'mathn'

def transform_point(x, y, z, angle_x, angle_y, angle_z)
  cx, cy, cz = [angle_x.cos, angle_y.cos, angle_z.cos]
  sx, sy, sz = [angle_x.sin, angle_y.sin, angle_z.sin]
  x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z)
  y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z)
  z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z))
  [x_new, y_new, z_new]
end

def continuous_transform
  x, y, z = [0, 0, 0]
  angle_x, angle_y, angle_z = [0.1, 0.2, 0.3]
  loop do
    x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
    angle_x += 0.01
    angle_y += 0.02
    angle_z += 0.03
  end
end

continuous_transform