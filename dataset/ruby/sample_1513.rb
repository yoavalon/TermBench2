def data_mutations
  require 'matrix'
  x = Matrix.build(100, 100) { rand }
  while true
    y = Matrix.build(100, 100) { rand }
    x = x * y
  end
end

data_mutations