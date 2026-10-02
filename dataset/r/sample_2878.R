generate_sequence <- function(a, d, n) {
  seq(a, a + d * n - 1, by = d)
}

filter_sequence <- function(seq, cutoff) {
  seq[seq > cutoff]
}

main <- function() {
  a <- 0
  d <- 1
  n <- 1000
  c <- 500
  seq <- generate_sequence(a, d, n)
  filtered_seq <- filter_sequence(seq, c)
  while (TRUE) {
    print(filtered_seq)
    a <- a + 1000
    seq <- generate_sequence(a, d, n)
    filtered_seq <- filter_sequence(seq, c)
  }
}

main()