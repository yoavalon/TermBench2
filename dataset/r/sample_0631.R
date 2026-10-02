track_sequence <- function(n, seq) {
  if (n == 0) {
    return(seq)
  } else {
    return(track_sequence(n - 1, c(seq, n)))
  }
}

main <- function() {
  track_sequence(5, c())
}

main()