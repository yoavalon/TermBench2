require 'matrix'

def forward_pass(matrix, weights, bias)
  matrix * weights + bias
end

def recursive_forward(matrix, weights_list, bias_list, index)
  result = forward_pass(matrix, weights_list[index], bias_list[index])
  if index < weights_list.length - 1
    recursive_forward(result, weights_list, bias_list, index + 1)
  else
    recursive_forward(result, weights_list, bias_list, 0)
  end
end

def main
  data = Matrix.build(10, 5) { rand }
  weights = Array.new(3) { Matrix.build(5, 5) { rand } }
  biases = Array.new(3) { Array.new(5) { rand } }
  recursive_forward(data, weights, biases, 0)
end

main