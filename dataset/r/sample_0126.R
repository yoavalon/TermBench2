process_connection <- function(state, data) {
  if (state == 'init') {
    if (data == 'connect') {
      return('connected')
    }
  } else if (state == 'connected') {
    if (data == 'data') {
      return('processing')
    } else if (data == 'disconnect') {
      return('disconnected')
    }
  } else if (state == 'processing') {
    if (data == 'complete') {
      return('connected')
    } else if (data == 'disconnect') {
      return('disconnected')
    }
  } else if (state == 'disconnected') {
    if (data == 'connect') {
      return('connected')
    }
  }
  return(state)
}

main <- function() {
  states <- c('init', 'connected', 'processing', 'disconnected')
  data_sequence <- c('connect', 'data', 'complete', 'disconnect', 'connect')
  current_state <- 'init'
  for (data in data_sequence) {
    current_state <- process_connection(current_state, data)
    if (!current_state %in% states) {
      break
    }
  }
}

main()