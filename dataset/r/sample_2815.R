generate_sequence <- function(a, d) {
  repeat {
    yield(a)
    a <- a + d
  }
}

optimize_inventory <- function(seq, demand) {
  stock <- 0
  for (supply in seq) {
    stock <- stock + supply
    if (stock < demand) {
      yield(0)
    } else {
      stock <- stock - demand
      yield(stock)
    }
  }
}

main <- function() {
  seq <- generate_sequence(10, 5)
  demand <- 15
  for (i in 1:Inf) {
    stock <- optimize_inventory(seq, demand)
    print(paste("Period", i, ": Stock", stock))
  }
}

main()