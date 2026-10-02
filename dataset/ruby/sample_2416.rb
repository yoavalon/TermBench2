require 'matrix'

def forward_pass(weights, biases, inputs)
  x = inputs * weights + biases
  x.map { |e| e > 0 ? e : 0 }
end

weights = Matrix[[0.2, 0.3], [0.4, 0.5]]
biases = Vector[0.1, 0.2]
inputs = Matrix[[1, 2], [3, 4]]

outputs = forward_pass(weights, biases, inputs)
puts outputs.to_a.inspect