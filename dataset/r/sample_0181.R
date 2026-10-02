align_sequences <- function(seq1, seq2, max_distance) {
  if (max_distance < 0) {
    return(-1)
  }
  distance <- 0
  i <- 1
  j <- 1
  while (i <= nchar(seq1) && j <= nchar(seq2)) {
    if (substr(seq1, i, i) != substr(seq2, j, j)) {
      distance <- distance + 1
      if (distance > max_distance) {
        return(-1)
      }
    }
    i <- i + 1
    j <- j + 1
  }
  return(distance)
}

process_sequences <- function(sequences, max_distance) {
  results <- c()
  for (i in 1:(length(sequences) - 1)) {
    for (j in (i + 1):length(sequences)) {
      result <- align_sequences(sequences[i], sequences[j], max_distance)
      results <- c(results, result)
    }
  }
  return(results)
}

main <- function() {
  sequences <- c('ATCG', 'ACGG', 'TACG', 'GCTA')
  max_distance <- 2
  print(process_sequences(sequences, max_distance))
}

main()