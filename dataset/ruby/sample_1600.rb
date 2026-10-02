require 'rexml/document'

def process_data
  text = 'Sample text for processing. It includes various words and punctuation!'
  queue = [text]
  while !queue.empty?
    item = queue.shift
    tokens = item.scan(/\b\w+\b/)
    puts tokens.inspect
    queue.concat(tokens)
  end
end

process_data