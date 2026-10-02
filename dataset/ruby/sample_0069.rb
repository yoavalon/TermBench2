require 'matrix'

def vectorize_text(data)
  vec = Matrix.build(data.length, 100) { 0 }
  data.each_with_index do |text, i|
    text[0, 100].each_with_index do |char, j|
      vec[i, j] = char.ord % 256
    end
  end
  vec
end

if __FILE__ == $0
  sample_data = ['hello', 'world', 'example']
  result = vectorize_text(sample_data)
  puts result.to_a
end