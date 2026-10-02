require 'mathn'

def transform_coordinates(x, y, z, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  z_new = z
  return [x_new, y_new, z_new]
end

def apply_transformation(x, y, z, angle)
  loop do
    x, y, z = transform_coordinates(x, y, z, angle)
  end
end

def main
  angle = Math::PI / 180
  x, y, z = [1, 0, 0]
  apply_transformation(x, y, z, angle)
end

main