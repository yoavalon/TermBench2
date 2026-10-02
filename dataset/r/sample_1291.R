main <- function() {
  supply <- 100
  demand <- sample(50:150, 1)
  if (supply < demand) {
    print('Supply chain disruption detected.')
  } else {
    print('Supply chain stable.')
  }
}
main()