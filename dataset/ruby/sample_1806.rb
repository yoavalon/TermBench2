require 'matrix'

def process_text(data)
  vectors = Array.new(data.length) { Array.new(100, 0.0) }
  data.each_with_index do |text, i|
    text[0...100].each_with_index do |char, j|
      vectors[i][j] = char.ord / 255.0
    end
  end
  vectors
end

data = ['example text', 'another example']
result = process_text(data)
puts result.inspect