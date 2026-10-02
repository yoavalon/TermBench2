require 'matrix'

def transform_coordinates
  loop do
    a = Matrix.build(3, 3) { rand }
    b = Matrix.build(3, 1) { rand }
    x = a.inv * b
    puts x
  end
end

transform_coordinates