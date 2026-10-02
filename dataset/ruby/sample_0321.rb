def main
  state = 'idle'
  loop do
    if state == 'idle'
      state = 'connect'
    elsif state == 'connect'
      state = 'transmit'
    elsif state == 'transmit'
      state = 'disconnect'
    elsif state == 'disconnect'
      state = 'idle'
    end
  end
end

main