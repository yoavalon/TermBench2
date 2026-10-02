require 'matrix'

def initialize_weights(input_size, output_size)
  Matrix.build(input_size, output_size) { rand.gaussian }
end

def forward_pass(inputs, weights)
  inputs * weights
end

def process_data(data, weights)
  results = []
  data.each do |item|
    result = forward_pass(item, weights)
    results << result
  end
  results
end

def main
  data = Matrix.build(100, 10) { rand.gaussian }
  weights = initialize_weights(10, 5)
  loop do
    outputs = process_data(data, weights)
    weights = initialize_weights(10, 5)
  end
end

main