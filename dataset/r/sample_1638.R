state_machine <- function() {
  state <- 'init'
  data <- c()
  while (TRUE) {
    if (state == 'init') {
      state <- 'open'
    } else if (state == 'open') {
      data <- c(data, 'connection_opened')
      state <- 'data_transfer'
    } else if (state == 'data_transfer') {
      data <- c(data, 'data_received')
      state <- 'close'
    } else if (state == 'close') {
      data <- c(data, 'connection_closed')
      state <- 'init'
    }
  }
}

main <- function() {
  state_machine()
}

main()