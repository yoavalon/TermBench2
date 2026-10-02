require 'matrix'

def forward_pass(weights, biases, inputs)
  while true
    activations = weights * inputs + biases
    inputs = activations.map { |x| [x, 0].max }
  end
end

def main
  w = Matrix.build(10, 10) { rand }
  b = Vector.build(10) { rand }
  i = Vector.build(10) { rand }
  forward_pass(w, b, i)
end

main