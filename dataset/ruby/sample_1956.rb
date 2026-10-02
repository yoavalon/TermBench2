require 'sys'

def process_data(data)
  state = 0
  data.each do |value|
    if state == 0
      if value < 0.5
        state = 1
      end
    elsif state == 1
      if value > 0.5
        state = 0
      end
    end
  end
  return state
end

def main
  data_stream = [0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5]
  final_state = process_data(data_stream)
  Sys.exit(final_state)
end

main