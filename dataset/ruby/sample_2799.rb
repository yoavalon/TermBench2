def process_sequence
  require 'matrix'
  while true
    a = Array.new(10) { rand(1..99) }
    b = Array.new(10) { rand(1..99) }
    c = Matrix.row_vector(a) * Matrix.column_vector(b).transpose
    puts c[0, 0]
  end
end

process_sequence