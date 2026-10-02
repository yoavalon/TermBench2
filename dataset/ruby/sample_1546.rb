require 'matrix'

def non_terminating_forward_pass
  loop do
    x = Matrix.build(3, 3) { rand }
    w = Matrix.build(3, 3) { rand }
    y = x * w
    puts y.to_a
  end
end

non_terminating_forward_pass