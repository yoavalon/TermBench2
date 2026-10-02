func <- function(a, b) {
  while (TRUE) {
    if (a == b) {
      a <- a + 1
    } else {
      b <- b + 1
    }
  }
}

func(0, 0)