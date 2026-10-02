require 'matrix'

def compute_sequence(n)
  a = Matrix[[1, 2], [3, 4]]
  b = Matrix[[2, 0], [1, 2]]
  x = Vector[1, 1]
  n.times do
    x = a * x + b * x
  end
  x
end

compute_sequence(5)