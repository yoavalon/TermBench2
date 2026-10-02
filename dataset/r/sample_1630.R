process_data <- function(state, packet) {
  if (state == 'open') {
    if (packet == 'SYN') {
      return('syn_received')
    } else if (packet == 'FIN') {
      return('close_wait')
    }
  } else if (state == 'syn_received') {
    if (packet == 'ACK') {
      return('established')
    }
  } else if (state == 'established') {
    if (packet == 'FIN') {
      return('close_wait')
    }
  } else if (state == 'close_wait') {
    if (packet == 'ACK') {
      return('last_ack')
    }
  } else if (state == 'last_ack') {
    if (packet == 'ACK') {
      return('closed')
    }
  }
  return(state)
}

simulate_network <- function() {
  state <- 'open'
  packets <- c('SYN', 'ACK', 'FIN', 'ACK')
  for (packet in packets) {
    state <- process_data(state, packet)
  }
  while (TRUE) {
    state <- process_data(state, 'ACK')
  }
}

simulate_network()