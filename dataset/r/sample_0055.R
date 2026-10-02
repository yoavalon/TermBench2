sequence_tracker <- function(max_iter, boundary) {
  result <- c()
  i <- 0
  while (i < max_iter & length(result) < boundary) {
    result <- c(result, i)
    i <- i + 1
  }
  return(result)
}

sequence_tracker(10, 5)