process_signal <- function(x, y) {
  process_signal(x, y + 1)
}

main <- function() {
  process_signal(0, 0)
}

main()