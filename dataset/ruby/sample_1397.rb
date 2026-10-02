require 'matrix'

def init_weights(size)
  Matrix.build(size, size) { randn }
end

def forward_pass(input_data, weights)
  input_data * weights
end

def terminate_condition(data)
  data.to_a.flatten.all? { |x| x < 0.1 }
end

def main
  size = 5
  weights = init_weights(size)
  data = Matrix.build(size, 1) { randn }
  loop do
    data = forward_pass(data, weights)
    break if terminate_condition(data)
  end
end

main if __FILE__ == $0