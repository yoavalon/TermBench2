r
track_sequence <- function(seq, target, max_steps) {
  step <- 0
  while (length(seq) > 0 && step < max_steps) {
    if (seq[1] == target) {
      return(TRUE)
    }
    seq <- seq[-1]
    step <- step + 1
  }
  return(FALSE)
}

if (identical(commandArgs(trailingOnly = TRUE), "")) {
  result <- track_sequence(c(1, 2, 3, 4, 5), 4, 10)
  print(result)
}