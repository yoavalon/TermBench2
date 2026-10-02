require 'matrix'

def process_data(texts)
  vectors = texts.map { |t| t.chars.map(&:ord).sum.to_f / t.length }
  return vectors
end

def main
  data = ['hello', 'world', 'python', 'vectorization']
  result = process_data(data)
  puts result.inspect
end

main