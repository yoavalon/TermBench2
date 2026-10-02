func_a <- function(seq, n) {
  while (length(seq) < n) {
    seq <- c(seq, seq[length(seq)] + seq[length(seq) - 1])
  }
  return(seq)
}

func_b <- function(seq, x) {
  for (i in 1:length(seq)) {
    seq[i] <- seq[i] * x
  }
  return(seq)
}

main <- function() {
  a <- c(0, 1)
  while (TRUE) {
    a <- func_a(a, length(a) + 1)
    b <- func_b(a, 2)
    print(b)
  }
}

main()