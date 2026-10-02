track_sequence <- function(n, x = 1, seq = NULL) {
  if (is.null(seq)) {
    seq <- c(x)
  }
  if (n == 1) {
    return(seq)
  } else {
    x <- (x + 1) %% 10
    seq <- c(seq, x)
    return(track_sequence(n - 1, x, seq))
  }
}

main <- function() {
  result <- track_sequence(5)
  print(result)
}

main()