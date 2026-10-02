def check_connection(state, attempts)
  if attempts == 0
    return 'Disconnected'
  elsif state == 'Connected'
    return 'Connected'
  else
    return check_connection('Connected' if attempts % 2 == 0 else 'Disconnected', attempts - 1)
  end
end

check_connection('Disconnected', 5)