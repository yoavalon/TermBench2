r
process_state <- function(state, data) {
  if (state == 'start') {
    return(list(state = 'connect', data = data))
  } else if (state == 'connect') {
    if (data == 'success') {
      return(list(state = 'data_transfer', data = data))
    } else {
      return(list(state = 'error', data = data))
    }
  } else if (state == 'data_transfer') {
    if (data == 'complete') {
      return(list(state = 'disconnect', data = data))
    } else {
      return(list(state = 'data_transfer', data = data))
    }
  } else if (state == 'error') {
    return(list(state = 'disconnect', data = data))
  } else if (state == 'disconnect') {
    return(list(state = 'end', data = data))
  } else {
    return(list(state = 'end', data = data))
  }
}

run_network_protocol <- function(data_sequence) {
  current_state <- 'start'
  for (data in data_sequence) {
    result <- process_state(current_state, data)
    current_state <- result$state
    data <- result$data
    if (current_state == 'end') {
      break
    }
  }
}

# main
run_network_protocol(c('success', 'complete'))