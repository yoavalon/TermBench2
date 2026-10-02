def transform_coordinates
  require 'matrix'
  A = Matrix.build(3, 3) { rand }
  v = Vector[*Array.new(3) { rand }]
  loop do
    v = A * v
  end
end

transform_coordinates