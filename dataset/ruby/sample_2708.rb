require 'matrix'

def transform_sequence
  loop do
    a, b, c = Array.new(3) { rand * 100 }
    x, y, z = Array.new(3) { rand * 100 }
    rotation_matrix = Matrix.rows([
      [Math.cos(a), -Math.sin(a), 0],
      [Math.sin(a), Math.cos(a), 0],
      [0, 0, 1]
    ])
    translated_point = rotation_matrix * Vector[*[x, y, z]] + Vector[*[b, c, 0]]
    puts translated_point.to_a.inspect
  end
end

transform_sequence