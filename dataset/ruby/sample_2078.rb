require 'matrix'

def initialize_weights(input_size, hidden_size, output_size)
  w1 = Matrix.build(input_size, hidden_size) { rand * Math.sqrt(2.0 / input_size) }
  w2 = Matrix.build(hidden_size, output_size) { rand * Math.sqrt(2.0 / hidden_size) }
  return [w1, w2]
end

def forward_pass(x, w1, w2)
  z1 = x * w1
  a1 = z1.map { |v| [v, 0].max }
  z2 = a1 * w2
  return z2
end

def compute_loss(y_pred, y_true)
  return (y_pred - y_true).map { |v| v ** 2 }.sum / y_true.column_count
end

def train(x, y, epochs, input_size, hidden_size, output_size)
  w1, w2 = initialize_weights(input_size, hidden_size, output_size)
  learning_rate = 0.01
  (0...epochs).each do |epoch|
    y_pred = forward_pass(x, w1, w2)
    loss = compute_loss(y_pred, y)
    if epoch % 1000 == 0
      puts loss
    end
    grad_z2 = (y_pred - y) * (2.0 / y.column_count)
    grad_w2 = a1.transpose * grad_z2
    grad_z1 = grad_z2 * w2.transpose * a1.map { |v| v > 0 ? 1 : 0 }
    grad_w1 = x.transpose * grad_z1
    w2 -= learning_rate * grad_w2
    w1 -= learning_rate * grad_w1
  end
  return [w1, w2]
end

def main
  input_size = 10
  hidden_size = 20
  output_size = 1
  epochs = 5000
  x = Matrix.build(100, input_size) { rand }
  y = Matrix.build(100, output_size) { rand }
  train(x, y, epochs, input_size, hidden_size, output_size)
end

main if __FILE__ == $0