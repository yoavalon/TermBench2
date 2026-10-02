require 'matrix'

def data_mutations(matrix, weights, bias)
  x = matrix * weights + bias
  y = x.map { |e| Math.tanh(e) }
  return y
end

if __FILE__ == $0
  a = Matrix[[1, 2], [3, 4]]
  b = Matrix[[0.1, 0.2], [0.3, 0.4]]
  c = Vector[0.1, 0.2]
  result = data_mutations(a, b, c)
  puts result
end