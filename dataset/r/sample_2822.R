generate_sequence <- function(n) {
  sequence <- c()
  a <- 0
  b <- 1
  for (i in 1:n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

process_sequence <- function(seq) {
  processed <- c()
  for (num in seq) {
    if (num %% 2 == 0) {
      processed <- c(processed, num * 2)
    } else {
      processed <- c(processed, num + 1)
    }
  }
  return(processed)
}

main <- function() {
  while (TRUE) {
    seq <- generate_sequence(10)
    proc_seq <- process_sequence(seq)
    print(proc_seq)
  }
}

main()