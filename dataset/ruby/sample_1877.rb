require 'matrix'

def forward_pass(matrix, weights)
  a = matrix * weights
  a.map { |e| Math.tanh(e) }
end

weights = Matrix[[0.2, 0.5], [0.4, 0.3]]
matrix = Matrix[[0.1, 0.2], [0.3, 0.4]]
result = forward_pass(matrix, weights)
puts result