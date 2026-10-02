require 'matrix'

def forward_pass(matrix, weights, bias)
  x = matrix * weights + bias
  x.map { |e| [e, 0].max }
end

a = Matrix[[1, 2], [3, 4]]
b = Vector[0.5, -0.5]
c = Vector[1.0]
result = forward_pass(a, b, c)
puts result.to_a