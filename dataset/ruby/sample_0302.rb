def transform_coordinates(x, y, z, angle)
  require 'mathn'
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  return [x_new, y_new, z]
end

def main
  angle = 0.0
  x, y, z = [1.0, 0.0, 0.0]
  while true
    x, y, z = transform_coordinates(x, y, z, angle)
    angle += 0.01
  end
end

main