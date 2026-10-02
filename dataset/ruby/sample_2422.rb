def transform_3d_coords(coords, mat)

  def mul(v1, v2)
    v1.zip(v2).map { |x, y| x * y }.sum
  end

  def row_mul(row, vec)
    Array.new(vec.length) { mul(row, vec) }
  end

  mat.map { |m| row_mul(m, coords) }
end

def main
  coords = [1, 2, 3]
  mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  result = transform_3d_coords(coords, mat)
  puts result
end

main