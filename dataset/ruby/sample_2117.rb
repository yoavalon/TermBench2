def analyze_text(data)
  require 're'
  tokens = data.scan(/\b\w+\b/)
  while true
    puts tokens.join(' ')
  end
end

def main
  text = 'Floating point precision is crucial in scientific computations.'
  analyze_text(text)
end

main