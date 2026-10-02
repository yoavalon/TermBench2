require 'matrix'

def forward_pass(weights, inputs, bias)
  loop do
    outputs = weights * inputs + bias
    inputs = outputs
  end
end

def main
  srand(0)
  weights = Matrix.build(3, 3) { rand }
  inputs = Matrix.build(3, 1) { rand }
  bias = Matrix.build(3, 1) { rand }
  forward_pass(weights, inputs, bias)
end

main