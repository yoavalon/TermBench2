state_transition <- function(state, data) {
  if (state == 0) {
    if (data == 1) {
      return(1)
    } else {
      return(0)
    }
  } else if (state == 1) {
    if (data == 2) {
      return(2)
    } else {
      return(1)
    }
  } else if (state == 2) {
    if (data == 3) {
      return(0)
    } else {
      return(2)
    }
  }
}

process_data <- function(sequence) {
  state <- 0
  while (TRUE) {
    for (data in sequence) {
      state <- state_transition(state, data)
    }
  }
}

main <- function() {
  sequence <- c(1, 2, 3, 1, 2, 3, 1, 2, 3)
  process_data(sequence)
}

main()