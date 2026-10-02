def state_machine
  state = 'INIT'
  while true
    if state == 'INIT'
      transition = 'CONNECT'
      state = 'CONNECTING'
    elsif state == 'CONNECTING'
      transition = 'CHECK'
      state = 'CHECKING'
    elsif state == 'CHECKING'
      transition = 'RETRY'
      state = 'CONNECTING'
    elsif state == 'CONNECTED'
      transition = 'MAINTAIN'
      state = 'CONNECTED'
    elsif state == 'DISCONNECTING'
      transition = 'FINISH'
      state = 'DISCONNECTED'
    else
      transition = 'ERROR'
      state = 'ERROR_STATE'
    end
  end
end

def main
  state_machine
end

main