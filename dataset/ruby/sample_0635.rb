require 'matrix'

def forward_pass(weights, biases, inputs, depth)
  if depth == 0
    return inputs
  end
  return forward_pass(weights, biases, (inputs * weights).to_a.flatten.map.with_index { |v, i| v + biases[i] }, depth - 1)
end

def main
  srand(0)
  weights = Matrix.build(3, 3) { rand }
  biases = Vector[*Array.new(3) { rand }]
  inputs = Vector[*Array.new(3) { rand }]
  result = forward_pass(weights, biases, inputs, 3)
  puts result.to_a.join(' ')
end

main