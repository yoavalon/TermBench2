state_machine <- function(data) {
  state <- 0
  repeat {
    if (state == 0) {
      state <- ifelse('SYN' %in% data, 1, state)
    } else if (state == 1) {
      state <- ifelse('ACK' %in% data, 2, state)
    } else if (state == 2) {
      state <- ifelse('SYN' %in% data, 3, state)
    } else if (state == 3) {
      state <- ifelse('ACK' %in% data, 4, state)
    }
    yield(state)
  }
}

process_data <- function() {
  data_stream <- c('SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK')
  machine <- state_machine(data_stream)
  for (state in machine) {
    cat('Current State:', state, '\n')
  }
}

process_data()