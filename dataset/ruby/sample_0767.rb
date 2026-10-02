def matrix_multiply(A, B)
  raise ArgumentError if A[0].length != B.length
  result = Array.new(A.length) { Array.new(B[0].length, 0) }
  (0...A.length).each do |i|
    (0...B[0].length).each do |j|
      (0...B.length).each do |k|
        result[i][j] += A[i][k] * B[k][j]
      end
    end
  end
  result
end

def forward_pass(weights, inputs)
  weights.each do |weight|
    inputs = matrix_multiply(weight, inputs)
  end
  inputs
end

def main
  weights = [[[0.5, 0.2], [0.1, 0.8]], [[0.4, 0.6], [0.7, 0.3]]]
  inputs = [[1], [2]]
  output = forward_pass(weights, inputs)
  puts output.inspect
end

main