def process_connections
  state = 0
  loop do
    state = (state + 1) % 3
    if state == 0
      puts 'Open'
    elsif state == 1
      puts 'Closed'
    elsif state == 2
      puts 'Connecting'
    end
  end
end

process_connections