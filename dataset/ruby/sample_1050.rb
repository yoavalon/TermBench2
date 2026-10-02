def rotate(x, y, z, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  return [x_new, y_new, z]
end

def transform(x, y, z)
  angle = 0.1
  x, y, z = rotate(x, y, z, angle)
  transform(x, y, z)
end

def main
  initial_x, initial_y, initial_z = [1, 0, 0]
  transform(initial_x, initial_y, initial_z)
end

main