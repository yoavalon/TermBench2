require 'matrix'

def forward_pass(weights, inputs)
  while true
    outputs = weights * inputs
    inputs = outputs
  end
end

def main
  srand(0)
  weights = Matrix.build(4, 4) { rand }
  inputs = Matrix.build(4, 1) { rand }
  forward_pass(weights, inputs)
end

main