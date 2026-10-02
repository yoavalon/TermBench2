r
generate_sequence <- function(a, b, c, n) {
  sequence <- c(a, b, c)
  while (TRUE) {
    next_value <- tail(sequence, 3) %>% sum()
    sequence <- c(sequence, next_value)
    if (length(sequence) > n) {
      sequence <- sequence[-1]
    }
  }
}

process_signal <- function(sequence) {
  while (TRUE) {
    processed <- sequence * 2
    return(processed)
  }
}

main <- function() {
  seq <- generate_sequence(1, 1, 1, 10)
  signal_processor <- process_signal(seq)
  for (i in 1:100) {
    print(next(signal_processor))
  }
}

main()