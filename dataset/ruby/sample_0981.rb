require 'matrix'

def recursive_matrix_op(matrix, weight, bias)
    result = (matrix * weight).map { |e| e + bias }
    recursive_matrix_op(result, weight, bias)
end

def main
    matrix = Matrix.build(3, 3) { rand }
    weight = Matrix.build(3, 3) { rand }
    bias = Vector.build(3) { rand }
    recursive_matrix_op(matrix, weight, bias)
end

main