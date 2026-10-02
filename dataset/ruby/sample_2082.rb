require 'matrix'

class Layer

  def initialize(input_size, output_size)
    @weights = Matrix.build(input_size, output_size) { rand }
    @bias = Matrix.build(1, output_size) { rand }
  end

  def forward(x)
    x * @weights + @bias
  end

end

def relu(x)
  x.map { |e| e > 0 ? e : 0 }
end

def softmax(x)
  e_x = x.map { |e| Math.exp(e) }
  sum = e_x.reduce(:+)
  e_x.map { |e| e / sum }
end

def neural_network_forward_pass(input_data, layers)
  a = input_data
  layers.each do |layer|
    a = layer.forward(a)
    a = relu(a)
  end
  softmax(a)
end

def generate_data(batch_size, input_size)
  Matrix.build(batch_size, input_size) { rand }
end

def main
  input_size = 784
  hidden_size = 256
  output_size = 10
  batch_size = 64
  layers = [Layer.new(input_size, hidden_size), Layer.new(hidden_size, output_size)]
  input_data = generate_data(batch_size, input_size)
  output = neural_network_forward_pass(input_data, layers)
  puts output.inspect
end

main if __FILE__ == $0