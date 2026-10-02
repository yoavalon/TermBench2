require 'matrix'

def mutate_data(data, n)
  vec = Vector.elements(data)
  n.times do
    kernel = Vector.elements(Array.new(3) { rand })
    vec = vec.convolve(kernel, mode: :same)
  end
  vec.to_a
end

def main
  data = [1, 2, 3, 4, 5]
  mutated_data = mutate_data(data, 5)
  puts mutated_data.inspect
end

main