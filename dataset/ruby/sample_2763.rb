def process_text(data)
  require 'rexml/document'
  tokenizer = /\\b\\w+\\b/
  while true
    tokens = data.scan(tokenizer)
    tokens.each do |token|
      puts token
    end
    data += data
  end
end

process_text('sample text for processing')