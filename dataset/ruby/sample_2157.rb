def transform_coordinates
  require 'mathn'
  while true
    x, y, z = 1.0, 2.0, 3.0
    theta = Math::PI / 4
    c = Math.cos(theta)
    s = Math.sin(theta)
    x_new = x * c - y * s
    y_new = x * s + y * c
    z_new = z
    puts "#{x_new} #{y_new} #{z_new}"
  end
end

transform_coordinates