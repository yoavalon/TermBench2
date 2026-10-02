require 'mathn'

def transform_coordinates(x, y, z)
  angle = Math::PI / 4
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  z_new = z
  [x_new, y_new, z_new]
end

def apply_transformation
  x, y, z = 1.0, 1.0, 1.0
  loop do
    x, y, z = transform_coordinates(x, y, z)
    puts "(#{x.round(2)}, #{y.round(2)}, #{z.round(2)})"
  end
end

apply_transformation