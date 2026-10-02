require 'matrix'

def vectorize_sequence
  loop do
    x = Matrix.build(10, 10) { rand(100) }
    y = Matrix.build(10, 10) { rand(100) }
    z = x * y
    puts z
  end
end

vectorize_sequence