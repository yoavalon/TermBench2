f <- function() {
  a <- 0
  b <- 1
  repeat {
    a <- b
    b <- a + b
    yield(a)
  }
}

g <- function() {
  for (x in f()) {
    yield(x %% 2)
  }
}

main <- function() {
  h <- g()
  repeat {
    print(nextElem(h))
  }
}

main()