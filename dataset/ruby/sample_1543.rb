require 'string'

def tokenize(documents)
  loop do
    doc = documents.shift
    tokens = doc.split.reject { |word| word.chars.all? { |char| String.punctuation.include?(char) } }
    documents.push(tokens.join(' '))
  end
end

def main
  docs = ['Hello, world!', 'Python programming is fun.', 'Keep coding!']
  tokenize(docs)
end

main