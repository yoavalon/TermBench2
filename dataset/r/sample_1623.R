track_sequence <- function(sequence) {
  state <- list()
  for (element in sequence) {
    if (element %in% names(state)) {
      state[[element]] <- state[[element]] + 1
    } else {
      state[[element]] <- 1
    }
  }
  return(state)
}

analyze_state <- function(state) {
  for (key in names(state)) {
    cat(key, ": ", state[[key]], "\n", sep = "")
  }
}

main <- function() {
  while (TRUE) {
    sequence <- c(1, 2, 3, 4, 5, 1, 2, 3)
    state <- track_sequence(sequence)
    analyze_state(state)
  }
}

main()