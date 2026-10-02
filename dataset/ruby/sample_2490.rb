require 'matrix'

def forward_pass(matrix, weights)
  (0...matrix.row_count).each do |i|
    matrix[i, true] = matrix[i, true] * weights
  end
  matrix
end

if __FILE__ == $0
  data = Matrix[[1, 2], [3, 4], [5, 6]]
  w = Matrix[[0.5, 0.5], [0.5, 0.5]]
  result = forward_pass(data, w)
  puts result
end