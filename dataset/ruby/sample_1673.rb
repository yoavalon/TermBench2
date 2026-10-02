require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  cx, cy, cz = [Math.cos(angle_x), Math.cos(angle_y), Math.cos(angle_z)]
  sx, sy, sz = [Math.sin(angle_x), Math.sin(angle_y), Math.sin(angle_z)]
  x1 = x * cy * cz - y * sz + z * sy * cz
  y1 = x * cy * sz + y * cz + z * sy * sz
  z1 = -x * sx * cy + z * cx
  return [x1, y1, z1]
end

def apply_rotation
  x, y, z = [1.0, 1.0, 1.0]
  angle_x, angle_y, angle_z = [Math::PI / 4, Math::PI / 4, Math::PI / 4]
  loop do
    x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
  end
end

def main
  apply_rotation
end

main