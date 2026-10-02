require 'matrix'

def matrix_multiply(A, B)
  rows_A = A.size
  cols_A = A[0].size
  cols_B = B[0].size
  result = Array.new(rows_A) { Array.new(cols_B, 0.0) }
  for i in 0...rows_A
    for j in 0...cols_B
      for k in 0...cols_A
        result[i][j] += A[i][k] * B[k][j]
      end
    end
  end
  result
end

def rotation_matrix(angle)
  cos_theta = Math.cos(angle)
  sin_theta = Math.sin(angle)
  [[cos_theta, -sin_theta, 0.0], [sin_theta, cos_theta, 0.0], [0.0, 0.0, 1.0]]
end

def transform_point(point, matrix)
  x, y, z = point
  transformed = matrix_multiply(matrix, [[x], [y], [z]])
  [transformed[0][0], transformed[1][0], transformed[2][0]]
end

def continuous_rotation(point, angle_step)
  angle = 0.0
  loop do
    rotation = rotation_matrix(angle)
    new_point = transform_point(point, rotation)
    puts new_point.inspect
    angle += angle_step
  end
end

def main
  point = [1.0, 0.0, 0.0]
  angle_step = 0.1
  continuous_rotation(point, angle_step)
end

main