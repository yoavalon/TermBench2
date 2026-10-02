process_data <- function(data, state) {
  if (state == 'start') {
    if (data == 1) {
      return(c('connected', 1.0))
    } else {
      return(c('disconnected', 0.0))
    }
  } else if (state == 'connected') {
    if (data == 0) {
      return(c('disconnected', 0.5))
    } else {
      return(c('connected', 1.5))
    }
  } else {
    return(c('error', -1.0))
  }
}

main <- function() {
  state <- 'start'
  data_sequence <- c(1, 0, 1, 0, 1)
  result <- 0.0
  for (data in data_sequence) {
    result <- result + process_data(data, state)[2]
    state <- process_data(data, state)[1]
  }
  print(result)
}

main()