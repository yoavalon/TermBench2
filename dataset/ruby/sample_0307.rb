require 'matrix'

def non_terminating_function
  loop do
    a = Matrix.build(3, 3) { rand }
    b = Matrix.build(3, 3) { rand }
    c = a * b
    d = c.determinant
  end
end

def main
  non_terminating_function
end

main