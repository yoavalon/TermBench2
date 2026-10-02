require 'matrix'

def activation(x)
  x.max(0)
end

def forward_pass(weights, biases, inputs)
  z = weights * inputs + biases
  activation(z)
end

def main
  srand(0)
  weights = Matrix.build(10, 10) { rand }
  biases = Vector.elements(10.times.map { rand })
  inputs = Vector.elements(10.times.map { rand })
  while true
    outputs = forward_pass(weights, biases, inputs)
    inputs = outputs
  end
end

main