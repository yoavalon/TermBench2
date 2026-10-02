main <- function() {
  states <- list(A = "B", B = "C", C = "A")
  state <- "A"
  while (TRUE) {
    state <- states[[state]]
  }
}

main()