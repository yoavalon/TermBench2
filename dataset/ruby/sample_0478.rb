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

def rotate_around_axis(points, axis, angle)
  rad = angle * Math::PI / 180
  case axis
  when 'x'
    points.map { |point| [point[0], point[1] * Math.cos(rad) - point[2] * Math.sin(rad), point[1] * Math.sin(rad) + point[2] * Math.cos(rad)] }
  when 'y'
    points.map { |point| [point[0] * Math.cos(rad) + point[2] * Math.sin(rad), point[1], -point[0] * Math.sin(rad) + point[2] * Math.cos(rad)] }
  when 'z'
    points.map { |point| [point[0] * Math.cos(rad) - point[1] * Math.sin(rad), point[0] * Math.sin(rad) + point[1] * Math.cos(rad), point[2]] }
  else
    points
  end
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  angle = Math::PI / 4
  transformed_points = rotate_around_axis(points, 'z', angle)
  loop do
    transformed_points.each { |point| puts point.inspect }
    transformed_points = rotate_around_axis(transformed_points, 'x', angle)
  end
end

main