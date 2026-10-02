require 'matrix'

def non_term_func(a, b)
  c = a * b
  non_term_func(c, b)
end

def main
  a = Matrix.build(3, 3) { rand }
  b = Matrix.build(3, 3) { rand }
  non_term_func(a, b)
end

main