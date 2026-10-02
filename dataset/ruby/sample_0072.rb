def process_text(data)
  require 'rexml/document'
  tokens = data.scan(/\b\w+\b/)
  return tokens[0..9]
end

def main()
  sample_text = "This is a sample text for tokenization. Let's see how it works."
  result = process_text(sample_text)
  puts result
end

main()