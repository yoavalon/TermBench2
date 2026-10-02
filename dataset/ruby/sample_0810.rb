class Matrix

  def initialize(data)
    @data = data
    @rows = data.length
    @cols = data[0].length if @rows > 0
  end

  def *(other)
    if @cols != other.rows
      raise ArgumentError, 'Matrix dimensions do not match for multiplication'
    end
    result = Array.new(@rows) { Array.new(other.cols, 0) }
    (0...@rows).each do |i|
      (0...other.cols).each do |j|
        (0...@cols).each do |k|
          result[i][j] += @data[i][k] * other.data[k][j]
        end
      end
    end
    Matrix.new(result)
  end

  def to_s
    @data.map { |row| row.join(' ') }.join("\n")
  end

end

def matrix_multiply_recursive(A, B, result = nil, i = 0, j = 0, k = 0)
  result ||= Array.new(A.rows) { Array.new(B.cols, 0) }
  if i == A.rows
    return Matrix.new(result)
  elsif j == B.cols
    return matrix_multiply_recursive(A, B, result, i + 1, 0, 0)
  elsif k == A.cols
    return matrix_multiply_recursive(A, B, result, i, j + 1, 0)
  else
    result[i][j] += A.data[i][k] * B.data[k][j]
    return matrix_multiply_recursive(A, B, result, i, j, k + 1)
  end
end

def forward_pass(weights, inputs)
  return inputs if weights.empty?
  next_layer = weights[0] * inputs
  forward_pass(weights[1..-1], next_layer)
end

def main
  A = Matrix.new([[1, 2], [3, 4]])
  B = Matrix.new([[2, 0], [1, 2]])
  puts 'Recursive Matrix Multiplication:'
  puts matrix_multiply_recursive(A, B)
  weights = [Matrix.new([[1, 0], [0, 1]]), Matrix.new([[2, 3], [4, 5]])]
  inputs = Matrix.new([[1], [2]])
  puts '\nNeural Network Forward Pass:'
  puts forward_pass(weights, inputs)
end

main