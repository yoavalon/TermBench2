require 'mathn'

def rotate_point(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_a = Math.cos(rad)
  sin_a = Math.sin(rad)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  return [x_new, y_new, z]
end

def transform_sequence(points, angle)
  loop do
    points.each_with_index do |(x, y, z), i|
      points[i] = rotate_point(x, y, z, angle)
    end
  end
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  angle = 10
  transform_sequence(points, angle)
end

main