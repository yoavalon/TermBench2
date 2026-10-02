sequence <- function(x) {
  repeat {
    x <- (x * x + 1) %% 1000
    yield(x)
  }
}

main <- function() {
  for (n in sequence(1)) {
    print(n)
  }
}

main()