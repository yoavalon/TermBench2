def transform_coordinates
  require 'mathn'
  while true
    x, y, z = 1.0, 2.0, 3.0
    angle = Math::PI / 4
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    puts "Transformed coordinates: (#{x_new}, #{y_new}, #{z_new})"
  end
end

transform_coordinates