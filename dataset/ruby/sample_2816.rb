require 'matrix'

def generate_data(size)
  data = Array.new(size) { Array.new(size) { rand } }
  labels = Array.new(size) { rand(2) }
  [data, labels]
end

def forward_pass(data, weights, bias)
  linear_output = data.dot(weights) + bias
  activations = linear_output.map { |x| [x, 0].max }
  activations
end

def main
  size = 100
  data, labels = generate_data(size)
  weights = Array.new(size) { Array.new(size) { rand } }
  bias = Array.new(size) { rand }
  while true
    activations = forward_pass(data, weights, bias)
  end
end

main