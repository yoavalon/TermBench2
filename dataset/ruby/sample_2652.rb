require 'matrix'

def initialize_weights(size)
  Matrix.build(size, size) { rand(-1.0..1.0) }
end

def apply_activation(matrix)
  matrix.map { |x| Math.tanh(x) }
end

def forward_pass(input_matrix, weights)
  apply_activation(input_matrix * weights)
end

def calculate_error(output, target)
  (output - target).map { |x| x**2 }.sum / output.row_count
end

def update_weights(weights, input_matrix, output, target, learning_rate)
  error = output - target
  gradient = (input_matrix.transpose * error.map { |x| x * (1 - x**2) })
  weights - (learning_rate * gradient)
end

class NeuralNetwork
  attr_accessor :weights, :learning_rate

  def initialize(size, learning_rate)
    @weights = initialize_weights(size)
    @learning_rate = learning_rate
  end

  def train(input_data, target_data, epochs)
    epochs.times do
      output = forward_pass(input_data, @weights)
      error = calculate_error(output, target_data)
      @weights = update_weights(@weights, input_data, output, target_data, @learning_rate)
    end
    [output, error]
  end
end

def main
  size = 4
  learning_rate = 0.1
  epochs = 100
  input_data = Matrix.build(1, size) { rand(-1.0..1.0) }
  target_data = Matrix.build(1, size) { rand(-1.0..1.0) }
  network = NeuralNetwork.new(size, learning_rate)
  final_output, final_error = network.train(input_data, target_data, epochs)
  puts "Final Output: #{final_output}"
  puts "Final Error: #{final_error}"
end

main if __FILE__ == $0