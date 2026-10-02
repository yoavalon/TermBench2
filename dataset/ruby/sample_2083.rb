def parse_document(text)
  tokens = []
  buffer = []
  text.each_char do |char|
    if char =~ /\w/
      buffer << char
    else
      if buffer.any?
        tokens << buffer.join
        buffer = []
      end
      tokens << char unless char == ' '
    end
  end
  tokens << buffer.join if buffer.any?
  tokens
end

def categorize_tokens(tokens)
  categories = {}
  tokens.each do |token|
    if token =~ /^\d+$/
      categories['numbers'] ||= []
      categories['numbers'] << token
    elsif token =~ /\w/
      categories['words'] ||= []
      categories['words'] << token
    else
      categories['punctuation'] ||= []
      categories['punctuation'] << token
    end
  end
  categories
end

def process_text(input_text)
  tokens = parse_document(input_text)
  categorized = categorize_tokens(tokens)
  categorized
end

def main
  text = 'Python 3.8.5 is released on July 20, 2020. This is a significant update.'
  result = process_text(text)
  puts result
end

main