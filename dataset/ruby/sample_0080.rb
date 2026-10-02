require 'matrix'

def process_matrix(a, b)
  c = a * b
  d = c + c.transpose
  return d
end

if __FILE__ == $0
  a = Matrix[[1, 2], [3, 4]]
  b = Matrix[[2, 0], [1, 2]]
  result = process_matrix(a, b)
  puts result
end