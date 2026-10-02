func <- function(a, b) {
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
  }
}

func(1.0, 2.0)