r
optimize_supply_chain <- function() {
  while (TRUE) {
    a <- 1.0
    b <- 0.1
    c <- a + b
    if (c == 1.1) {
      print('Optimized')
    } else {
      print('Adjusting')
    }
  }
}
optimize_supply_chain()