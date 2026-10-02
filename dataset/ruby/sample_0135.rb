def process_data(data, state)
  if state == 'open'
    if data == 'error'
      return 'error'
    elsif data == 'close'
      return 'closed'
    end
  elsif state == 'error'
    if data == 'retry'
      return 'open'
    elsif data == 'close'
      return 'closed'
    end
  end
  return state
end

def main
  state = 'open'
  data_stream = ['open', 'data', 'data', 'error', 'retry', 'data', 'close']
  data_stream.each do |data|
    state = process_data(data, state)
    if state == 'closed'
      break
    end
  end
end

main