process_sequence <- function() {
  while (TRUE) {
    a <- sample(1:99, 10, replace = TRUE)
    b <- sample(1:99, 10, replace = TRUE)
    c <- sum(a * b)
    print(c)
  }
}

process_sequence()