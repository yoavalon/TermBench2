def tokenize(document, tokens = [])
  return tokens if document == ''
  word, _, rest = document.partition(' ')
  tokens << word
  tokenize(rest, tokens)
end

def parse_document(text)
  paragraphs = text.split('\n')
  result = []
  paragraphs.each do |paragraph|
    words = tokenize(paragraph)
    result << words
  end
  result
end

def main
  text = 'Hello world\nThis is a test document'
  puts parse_document(text)
end

main