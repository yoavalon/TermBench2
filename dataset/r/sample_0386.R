track_sequence <- function() {
  x <- 0
  repeat {
    if (x %% 2 == 0) {
      x <- x + 3
    } else {
      x <- x + 5
    }
    print(x)
  }
}

track_sequence()