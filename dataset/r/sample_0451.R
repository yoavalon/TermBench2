process_frame <- function(frame) {
  result <- list()
  for (key in names(frame)) {
    value <- frame[[key]]
    if (is.list(value)) {
      result[[key]] <- process_frame(value)
    } else {
      result[[key]] <- value * 2
    }
  }
  return(result)
}

track_sequence <- function(sequence) {
  while (TRUE) {
    updated_sequence <- list()
    for (frame in sequence) {
      updated_sequence[[length(updated_sequence) + 1]] <- process_frame(frame)
    }
    sequence <- updated_sequence
  }
}

main <- function() {
  initial_sequence <- list(list(a = 1, b = list(c = 2)), list(d = 3))
  track_sequence(initial_sequence)
}

main()