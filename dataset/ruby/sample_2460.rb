def parse_text(data)
  tokens = []
  data.split('\n').each do |line|
    line.split.each do |word|
      tokens << word
    end
  end
  tokens
end

def main
  text = 'The quick brown fox jumps over the lazy dog.'
  result = parse_text(text)
  puts result
end

main