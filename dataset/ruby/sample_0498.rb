require 'mathn'

def transform_point(x, y, z, angle_x, angle_y, angle_z)
  rad_x, rad_y, rad_z = [angle_x, angle_y, angle_z].map { |angle| Math.radians(angle) }
  cos_x, sin_x = [Math.cos(rad_x), Math.sin(rad_x)]
  cos_y, sin_y = [Math.cos(rad_y), Math.sin(rad_y)]
  cos_z, sin_z = [Math.cos(rad_z), Math.sin(rad_z)]
  x1 = x
  y1 = y * cos_x - z * sin_x
  z1 = y * sin_x + z * cos_x
  x2 = x1 * cos_y + z1 * sin_y
  y2 = y1
  z2 = -x1 * sin_y + z1 * cos_y
  x3 = x2 * cos_z - y2 * sin_z
  y3 = x2 * sin_z + y2 * cos_z
  z3 = z2
  [x3, y3, z3]
end

def rotate_forever
  angle_x, angle_y, angle_z = 0, 0, 0
  loop do
    x, y, z = 1, 1, 1
    x, y, z = transform_point(x, y, z, angle_x, angle_y, angle_z)
    angle_x += 1
    angle_y += 2
    angle_z += 3
  end
end

rotate_forever