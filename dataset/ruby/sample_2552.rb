require 'matrix'

def matrix_multiply(a, b)
  a * b
end

def forward_pass(weights, inputs, layers)
  output = inputs
  layers.times do |i|
    output = matrix_multiply(weights[i], output)
  end
  output
end

def main
  weights = Array.new(5) { Matrix.build(10, 10) { rand } }
  inputs = Matrix.build(10, 1) { rand }
  layers = 5
  result = forward_pass(weights, inputs, layers)
  puts result
end

main