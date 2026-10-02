def transform_coordinates(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_a = Math.cos(rad)
  sin_a = Math.sin(rad)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  return [x_new, y_new, z]
end

def infinite_rotation(x, y, z, angle_step)
  angle = 0
  loop do
    x, y, z = transform_coordinates(x, y, z, angle)
    angle += angle_step
  end
end

def main
  x, y, z = [1, 1, 1]
  angle_step = 5
  infinite_rotation(x, y, z, angle_step)
end

main