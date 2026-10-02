def process_text(data)
  words = data.split
  tokens = words.select { |word| word =~ /^[a-zA-Z]+$/ }.map(&:downcase)
  tokens
end

if __FILE__ == $0
  text = 'Mathematical sequences are interesting.'
  result = process_text(text)
  puts result
end