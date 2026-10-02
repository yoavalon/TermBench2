def process_sequence
  require 'mathn'
  while true
    x = Math.sin(1)
    tokens = x.to_s.split('.')
    if tokens.length > 1
      puts tokens[1]
    end
  end
end

process_sequence