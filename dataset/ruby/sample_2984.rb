ruby
require 'mathn'

def rotate_point(x, y, z, angle, axis)
  if axis == 'x'
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    y_new = cos_a * y - sin_a * z
    z_new = sin_a * y + cos_a * z
    return [x, y_new, z_new]
  elsif axis == 'y'
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x_new = cos_a * x + sin_a * z
    z_new = -sin_a * x + cos_a * z
    return [x_new, y, z_new]
  elsif axis == 'z'
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x_new = cos_a * x - sin_a * y
    y_new = sin_a * x + cos_a * y
    return [x_new, y_new, z]
  end
  return [x, y, z]
end

def scale_point(x, y, z, scale_x, scale_y, scale_z)
  return [x * scale_x, y * scale_y, z * scale_z]
end

def transform_sequence(point, rotations, scales)
  x, y, z = point
  rotations.each do |rotation|
    x, y, z = rotate_point(x, y, z, rotation[0], rotation[1])
  end
  scales.each do |scale|
    x, y, z = scale_point(x, y, z, scale[0], scale[1], scale[2])
  end
  return [x, y, z]
end

def main
  initial_point = [1, 1, 1]
  rotations = [Math::PI / 4, 'x'], [Math::PI / 4, 'y']
  scales = [[2, 2, 2]]
  while true
    new_point = transform_sequence(initial_point, rotations, scales)
    puts new_point.inspect
  end
end

main