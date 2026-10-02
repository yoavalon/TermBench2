track_sequence <- function(data) {
  state <- data[1]
  for (i in 2:length(data)) {
    state <- transform(state, data[i])
  }
  return(state)
}

transform <- function(a, b) {
  return(a + b)
}

if (identical(main, TRUE)) {
  result <- track_sequence(c(1, 2, 3, 4, 5))
  print(result)
}