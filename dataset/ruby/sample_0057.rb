ruby
def transform_coordinates(coords, matrix)
  coords.map { |row| matrix.transpose.map { |col| row.zip(col).map { |a, b| a * b }.sum } }
end

def main
  coords = [[1, 2, 3], [4, 5, 6]]
  matrix = [[0, 1, 0], [-1, 0, 0], [0, 0, 1]]
  result = transform_coordinates(coords, matrix)
  puts result.inspect
end

main