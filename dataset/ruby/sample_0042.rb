require 'matrix'

def forward_pass(matrix, vector)
    result = matrix * vector
    return result
end

def main
    A = Matrix[[1, 2], [3, 4]]
    b = Vector[5, 6]
    output = forward_pass(A, b)
    puts output
end

main