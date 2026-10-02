require 'mathn'

def rotate_point(x, y, z, angle)
  cos_theta = Math.cos(angle)
  sin_theta = Math.sin(angle)
  x_new = x * cos_theta - y * sin_theta
  y_new = x * sin_theta + y * cos_theta
  [x_new, y_new, z]
end

def translate_point(x, y, z, dx, dy, dz)
  [x + dx, y + dy, z + dz]
end

def main
  x, y, z = 0, 0, 0
  dx, dy, dz = 1, 2, 3
  angle = Math::PI / 4
  loop do
    x, y, z = rotate_point(x, y, z, angle)
    x, y, z = translate_point(x, y, z, dx, dy, dz)
    puts "(#{x.round(2)}, #{y.round(2)}, #{z.round(2)})"
  end
end

main