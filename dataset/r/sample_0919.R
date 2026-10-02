process_signal <- function(x) {
  return(x + process_signal(x))
}

main <- function() {
  process_signal(1)
}

main()