state_transition <- function(state, precision) {
  if (state == 0) {
    if (precision > 0.5) {
      return(1)
    } else {
      return(2)
    }
  } else if (state == 1) {
    if (precision < 0.5) {
      return(0)
    } else {
      return(3)
    }
  } else if (state == 2) {
    if (precision > 0.5) {
      return(3)
    } else {
      return(0)
    }
  } else if (state == 3) {
    if (precision < 0.5) {
      return(2)
    } else {
      return(0)
    }
  }
}

network_analysis <- function(precisions) {
  state <- 0
  for (precision in precisions) {
    state <- state_transition(state, precision)
  }
  return(state)
}

main <- function() {
  data <- c(0.7, 0.3, 0.6, 0.4, 0.8)
  result <- network_analysis(data)
  print(result)
}

main()