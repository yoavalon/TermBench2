process_sequences <- function() {
  sequences <- c('hello world', 'data science', 'machine learning')
  vectors <- lapply(sequences, function(seq) {
    unlist(lapply(strsplit(seq, NULL)[[1]], function(c) {
      as.numeric(charToRaw(c))
    }))
  })
  return(vectors)
}

process_sequences()