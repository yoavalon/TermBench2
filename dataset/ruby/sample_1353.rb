def process_data(data)
  state = 'init'
  data.each do |item|
    if state == 'init'
      if item == 'connect'
        state = 'connected'
      elsif item == 'disconnect'
        state = 'disconnected'
      end
    elsif state == 'connected'
      if item == 'data'
        state = 'processing'
      elsif item == 'disconnect'
        state = 'disconnected'
      end
    elsif state == 'processing'
      if item == 'complete'
        state = 'connected'
      elsif item == 'disconnect'
        state = 'disconnected'
      end
    elsif state == 'disconnected'
      if item == 'connect'
        state = 'connected'
      end
    end
  end
  return state
end

def main()
  data_sequence = ['connect', 'data', 'complete', 'disconnect']
  result = process_data(data_sequence)
  puts result
end

main() if __FILE__ == $0