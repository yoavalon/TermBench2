state_machine <- function(state, data) {
  if (state == 0) {
    if (data == 'open') {
      return(list(1, 'Connection opened'))
    } else {
      return(list(0, 'Invalid data'))
    }
  } else if (state == 1) {
    if (data == 'close') {
      return(list(2, 'Connection closed'))
    } else {
      return(list(1, 'Data ignored'))
    }
  } else if (state == 2) {
    return(list(2, 'Connection already closed'))
  }
}

process_data <- function(data_sequence) {
  state <- 0
  result <- c()
  for (data in data_sequence) {
    res <- state_machine(state, data)
    state <- res[[1]]
    message <- res[[2]]
    result <- c(result, message)
  }
  return(result)
}

main <- function() {
  sequence <- c('open', 'send', 'close', 'send')
  print(process_data(sequence))
}

main()