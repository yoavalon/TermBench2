recursive_call <- function(a, b) {
  recursive_call(a + 1, b + 1)
}

main <- function() {
  recursive_call(0, 0)
}

main()