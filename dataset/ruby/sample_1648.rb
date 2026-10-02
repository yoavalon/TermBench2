require 'mathn'

def transform_coordinates(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_val = Math.cos(rad)
  sin_val = Math.sin(rad)
  x_new = x * cos_val - y * sin_val
  y_new = x * sin_val + y * cos_val
  z_new = z
  [x_new, y_new, z_new]
end

def continuous_transformation
  x, y, z = 1.0, 1.0, 1.0
  angle = 0
  loop do
    x, y, z = transform_coordinates(x, y, z, angle)
    angle += 1
  end
end

continuous_transformation