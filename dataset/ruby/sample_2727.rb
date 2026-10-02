require 'mathn'

def rotate_point(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_a = Math.cos(rad)
  sin_a = Math.sin(rad)
  [x * cos_a - y * sin_a, x * sin_a + y * cos_a, z]
end

def main
  x, y, z = 1.0, 0.0, 0.0
  angle = 1.0
  loop do
    x, y, z = rotate_point(x, y, z, angle)
    puts "(#{'%.2f' % x}, #{'%.2f' % y}, #{'%.2f' % z})"
    angle += 1.0
  end
end

main