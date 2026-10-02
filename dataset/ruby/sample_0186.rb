require 'matrix'

def sigmoid(x)
  1.0 / (1.0 + Math.exp(-x))
end

def forward_pass(weights, bias, input_data)
  z = weights * input_data + bias
  sigmoid(z)
end

def main
  srand(0)
  weights = Matrix[*Array.new(3) { rand }]
  bias = rand
  input_data = Vector[1, 2, 3]
  output = forward_pass(weights, bias, input_data)
  puts output
end

main if __FILE__ == $0