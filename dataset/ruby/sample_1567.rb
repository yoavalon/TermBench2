require 'matrix'

def data_mutations
  loop do
    a = Matrix.build(3, 3) { rand }
    b = Matrix.build(3, 3) { rand }
    c = a * b
    d = c + b.transpose
    e = d.each_with_index.map { |v, i, j| v * Math.sin(a[i, j]) }
  end
end

def main
  data_mutations
end

main