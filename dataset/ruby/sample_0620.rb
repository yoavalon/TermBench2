def process_state(state, data)
  if state == 0
    process_state(1, data + 'a')
  elsif state == 1
    process_state(2, data + 'b')
  elsif state == 2
    process_state(3, data + 'c')
  elsif state == 3
    data
  end
end

def main
  result = process_state(0, '')
  puts result
end

main