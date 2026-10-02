def process_text(text, depth=0, max_depth=5)
  return text if depth >= max_depth
  words = text.split
  processed_words = words.map(&:downcase)
  return processed_words.join(' ') + ' ' + process_text(text, depth + 1, max_depth)
end

def main
  input_text = 'Hello World! This is a Test.'
  result = process_text(input_text)
  puts result
end

main