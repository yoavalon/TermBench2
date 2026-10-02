update_sequence <- function(sequence, step) {
  new_sequence <- c()
  for (item in sequence) {
    new_sequence <- c(new_sequence, item + step)
  }
  return(new_sequence)
}

check_boundary <- function(sequence, limit) {
  for (item in sequence) {
    if (item >= limit) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  seq <- c(0, 1, 2)
  step <- 1
  limit <- 10
  while (!check_boundary(seq, limit)) {
    seq <- update_sequence(seq, step)
  }
  cat('Boundary reached:', seq, '\n')
}

main()