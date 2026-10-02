process_sequence <- function(seq) {
  states <- list(open = 0, closed = 1)
  transitions <- list(c(0, 1), c(1, 0))
  current <- states$open
  result <- c()
  for (i in seq_along(seq)) {
    current <- transitions[[current + 1]][ifelse(seq[i] %% 2 == 0, 1, 2)]
    result <- c(result, current)
  }
  return(result)
}

main <- function() {
  seq <- c(0, 1, 2, 3, 4, 5)
  print(process_sequence(seq))
}

main()