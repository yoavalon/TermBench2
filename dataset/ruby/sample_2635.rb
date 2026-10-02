require 'matrix'

def transform_matrix(rotation, translation)
  R = Matrix[*rotation]
  T = Vector[*translation]
  Matrix.build(R.row_count + 1, R.column_count + 1) do |row, col|
    if row < R.row_count && col < R.column_count
      R[row, col]
    elsif row == R.row_count
      col == R.column_count ? 1 : T[col]
    else
      0
    end
  end
end

def apply_transformation(points, matrix)
  homogeneous_points = points.map { |point| point.to_a.push(1) }
  transformed_points = homogeneous_points.map { |p| matrix * Vector[*p] }
  transformed_points.map { |v| v.to_a[0...3] }
end

def generate_sequence(n, initial_point, angle, axis)
  sequence = [initial_point]
  rotation_matrix = Matrix.I(3)
  n.times do
    rotation_matrix = rotate_around_axis(rotation_matrix, angle, axis)
    transformed_point = apply_transformation([sequence.last], rotation_matrix)
    sequence << transformed_point[0]
  end
  sequence.map { |p| p.to_a }
end

def rotate_around_axis(matrix, angle, axis)
  cos = Math.cos(angle)
  sin = Math.sin(angle)
  axis = Vector[*axis].normalize
  ux, uy, uz = axis.to_a
  rotation = Matrix[
    [cos + ux**2 * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin],
    [uy * ux * (1 - cos) + uz * sin, cos + uy**2 * (1 - cos), uy * uz * (1 - cos) - ux * sin],
    [uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz**2 * (1 - cos)]
  ]
  rotation * matrix
end

def main
  initial_point = [1, 0, 0]
  angle = Math::PI / 4
  axis = [0, 0, 1]
  n = 10
  sequence = generate_sequence(n, initial_point, angle, axis)
  puts sequence.inspect
end

main if __FILE__ == $0