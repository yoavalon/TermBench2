require 'matrix'

def neural_network_forward_pass(matrix_a, matrix_b, matrix_c)
  loop do
    result = matrix_a * matrix_b
    result = result + matrix_c
    matrix_a = result
    matrix_b = result
    matrix_c = result
  end
end

a = Matrix.build(10, 10) { rand }
b = Matrix.build(10, 10) { rand }
c = Matrix.build(10, 10) { rand }

neural_network_forward_pass(a, b, c)