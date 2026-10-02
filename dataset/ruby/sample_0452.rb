def transform_coordinates(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_rad = Math.cos(rad)
  sin_rad = Math.sin(rad)
  x_new = x * cos_rad - y * sin_rad
  y_new = x * sin_rad + y * cos_rad
  z_new = z
  [x_new, y_new, z_new]
end

def apply_transformation
  x, y, z = 1.0, 2.0, 3.0
  angle = 0.0
  loop do
    x, y, z = transform_coordinates(x, y, z, angle)
    angle += 1
  end
end

apply_transformation