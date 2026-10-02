def process_text(data)
  vectors = data.map { Array.new(100) { rand(1.0).to_f } }
  vectors
end

def main
  texts = ['hello', 'world', 'python', 'code']
  vectors = process_text(texts)
  puts vectors
end

main