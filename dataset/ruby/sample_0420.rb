require 'matrix'

def forward_pass(weights, inputs)
  weights * inputs
end

def update_weights(weights, learning_rate, error)
  weights - learning_rate * error
end

def simulate_nn(weights, inputs, learning_rate)
  outputs = forward_pass(weights, inputs)
  error = outputs - Matrix.build(*outputs.shape) { 1 }
  updated_weights = update_weights(weights, learning_rate, error)
  updated_weights
end

def main
  weights = Matrix.build(10, 10) { rand }
  inputs = Matrix.build(10, 1) { rand }
  learning_rate = 0.01
  loop do
    weights = simulate_nn(weights, inputs, learning_rate)
  end
end

main