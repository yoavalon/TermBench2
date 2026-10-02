require 'matrix'

def matrix_multiply(a, b)
  a * b
end

def relu(x)
  x.map { |v| [v, 0].max }
end

def forward_pass(input_data, weights)
  hidden_layer = relu(matrix_multiply(input_data, weights['w1']))
  output_layer = matrix_multiply(hidden_layer, weights['w2'])
  output_layer
end

def main
  input_data = Matrix.build(1, 10) { rand }
  weights = {
    'w1' => Matrix.build(10, 5) { rand },
    'w2' => Matrix.build(5, 1) { rand }
  }
  result = forward_pass(input_data, weights)
  puts result.to_a
end

main