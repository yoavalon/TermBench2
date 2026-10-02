track_sequence <- function(n, seq = c()) {
  if (n == 0) {
    return(seq)
  }
  seq <- c(seq, n)
  return(track_sequence(n - 1, seq))
}

main <- function() {
  result <- track_sequence(5)
  print(result)
}

main()