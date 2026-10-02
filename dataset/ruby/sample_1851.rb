require 'matrix'

def forward_pass(weights, inputs)
  activations = weights * inputs
  activations
end

if __FILE__ == $0
  a = Matrix.build(10, 5) { rand }
  b = Matrix.build(5, 3) { rand }
  c = forward_pass(a, b)
  puts c
end