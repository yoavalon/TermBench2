def parse_document(text)
  tokens = []
  buffer = ''
  text.each_char do |char|
    if char =~ /[a-zA-Z0-9.]/ || char == '.'
      buffer += char
    else
      if buffer.length > 0
        tokens.push(buffer)
        buffer = ''
      end
      if char != ' '
        tokens.push(char)
      end
    end
  end
  if buffer.length > 0
    tokens.push(buffer)
  end
  tokens
end

def main
  document = 'Example 1.23 and 4.567.'
  tokens = parse_document(document)
  puts tokens.inspect
end

main