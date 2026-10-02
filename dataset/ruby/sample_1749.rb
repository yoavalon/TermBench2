require 'matrix'

class NeuralNetwork

  def initialize(layers)
    @weights = layers.each_cons(2).map { |a, b| Matrix.build(a, b) { rand } }
    @biases = layers[1..-1].map { |b| Matrix.build(1, b) { rand } }
  end

  def sigmoid(x)
    1.0 / (1.0 + Math.exp(-x))
  end

  def forward_pass(input_data)
    activations = [input_data]
    @weights.zip(@biases).each do |w, b|
      z = activations.last * w + b
      activations << z.map { |e| sigmoid(e) }
    end
    activations.last
  end
end

class DataProcessor

  def initialize(data)
    @data = data
  end

  def normalize
    min_val = @data.min
    max_val = @data.max
    @data.map { |x| (x - min_val) / (max_val - min_val) }
  end

  def prepare_batches(batch_size)
    @data.each_slice(batch_size).to_a
  end
end

class Controller

  def initialize(nn, dp)
    @nn = nn
    @dp = dp
  end

  def process_data
    normalized_data = @dp.normalize
    batches = @dp.prepare_batches(10)
    batches.each do |batch|
      @nn.forward_pass(Matrix.rows(batch))
    end
  end
end

def main
  layers = [784, 128, 64, 10]
  nn = NeuralNetwork.new(layers)
  data = Array.new(1000) { Array.new(784) { rand } }
  dp = DataProcessor.new(data)
  controller = Controller.new(nn, dp)
  loop do
    controller.process_data
  end
end

main