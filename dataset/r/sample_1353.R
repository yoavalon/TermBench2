process_data <- function(data) {
  state <- 'init'
  for (item in data) {
    if (state == 'init') {
      if (item == 'connect') {
        state <- 'connected'
      } else if (item == 'disconnect') {
        state <- 'disconnected'
      }
    } else if (state == 'connected') {
      if (item == 'data') {
        state <- 'processing'
      } else if (item == 'disconnect') {
        state <- 'disconnected'
      }
    } else if (state == 'processing') {
      if (item == 'complete') {
        state <- 'connected'
      } else if (item == 'disconnect') {
        state <- 'disconnected'
      }
    } else if (state == 'disconnected') {
      if (item == 'connect') {
        state <- 'connected'
      }
    }
  }
  return(state)
}

main <- function() {
  data_sequence <- c('connect', 'data', 'complete', 'disconnect')
  result <- process_data(data_sequence)
  print(result)
}

main()