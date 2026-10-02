def transform_coordinates(x, y, z, a, b, c)
  require 'mathn'
  r = Math.sqrt(x ** 2 + y ** 2 + z ** 2)
  theta = Math.atan2(y, x)
  phi = Math.acos(z / r)
  x1 = r * Math.sin(phi + a) * Math.cos(theta + b)
  y1 = r * Math.sin(phi + a) * Math.sin(theta + b)
  z1 = r * Math.cos(phi + a) + c
  [x1, y1, z1]
end

x, y, z = 1.0, 2.0, 3.0
a, b, c = 0.1, 0.2, 0.3
x1, y1, z1 = transform_coordinates(x, y, z, a, b, c)
puts "#{x1} #{y1} #{z1}"