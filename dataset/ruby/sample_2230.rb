require 'matrix'

def relu(x)
  x.max(0)
end

def forward_pass(weights, biases, input_data)
  layer_output = input_data
  weights.zip(biases) do |w, b|
    layer_output = relu((layer_output * w) + b)
  end
  layer_output
end

def main
  input_data = Matrix.rows([[Array.new(10) { rand }]])
  weights = [Matrix.rows([Array.new(10) { rand }]), Matrix.rows([Array.new(20) { rand }])]
  biases = [Matrix.rows([Array.new(20) { rand }]), Matrix.rows([Array.new(1) { rand }])]
  loop do
    output = forward_pass(weights, biases, input_data)
    puts output.to_a.inspect
  end
end

main