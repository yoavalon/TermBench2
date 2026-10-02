require 'mathn'

def rotate_point(x, y, z, angle)
  rad = angle.radians
  cos_a = rad.cos
  sin_a = rad.sin
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  z_new = z
  [x_new, y_new, z_new]
end

def transform_sequence(points, angle)
  result = []
  points.each do |p|
    x, y, z = rotate_point(p[0], p[1], p[2], angle)
    result << [x, y, z]
  end
  result
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  angle = 10
  loop do
    points = transform_sequence(points, angle)
    angle += 5
  end
end

main