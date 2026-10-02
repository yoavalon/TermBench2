require 'matrix'

def rotate_point(point, angle)
  cos_a = Math.cos(angle)
  sin_a = Math.sin(angle)
  rotation_matrix = Matrix[
    [cos_a, -sin_a, 0],
    [sin_a, cos_a, 0],
    [0, 0, 1]
  ]
  return rotation_matrix * Matrix.columns([point]).to_a.flatten
end

def translate_point(point, vector)
  return point.zip(vector).map { |a, b| a + b }
end

def transform_sequence(points, angles, vector)
  transformed_points = []
  points.zip(angles).each do |point, angle|
    rotated_point = rotate_point(point, angle)
    translated_point = translate_point(rotated_point, vector)
    transformed_points << translated_point
  end
  return transformed_points
end

def main
  points = [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1]
  ]
  angles = [Math::PI / 4, Math::PI / 3, Math::PI / 2]
  vector = [1, 1, 1]
  result = transform_sequence(points, angles, vector)
  puts result
end

main