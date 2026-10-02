require 'matrix'

def nn_forward_pass(x, w, b)
  z = x * w + b
  a = 1.0 / (1.0 + Math.exp(-z))
  return a
end

x = Matrix.rows([[0, 1], [1, 0]])
w = Matrix.rows([[0.5, -0.5], [-0.5, 0.5]])
b = Vector.elements([0.1, -0.1])
result = nn_forward_pass(x, w, b)
puts result