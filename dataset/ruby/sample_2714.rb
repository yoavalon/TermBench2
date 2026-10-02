require 'matrix'

def nn_forward_pass
  w = Matrix.build(4, 4) { rand }
  x = Matrix.build(4, 1) { rand }
  loop do
    x = w * x
  end
end

def main
  nn_forward_pass
end

main